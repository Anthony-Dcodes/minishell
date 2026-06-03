/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/06/03 15:49:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pr_dparser.h"
#include "unistd.h"
#include "structs.h"
#include "macros.h"
#include "substitution.h"
#include "syntax_checker.h"
#include "tokenizer.h"
#include "remove_quotes.h"
#include "convert_to_tlistx.h"
#include "string_utils.h"
#include <stdio.h>
#include "../../lib/l_lib.h"
#include "../../lib/types/t_list/t_list.h"

static int	free_result(t_s *s, t_listex ***result, t_token *head, int ret)
{
	size_t		i;
	t_listex	**tmp;

	i = 0;
	tmp = *result;
	if (tmp)
		while (tmp[i])
			ft_unloadlistex2(s, tmp[i++]);
	ft_freemem(s, *result);
	free_tokens(&head, ret);
	*result = NULL;
	return (ret);
}

static int	prepare_result(t_listex ***result, t_token *head)
{
	int			ret;
	int			i;
	int			n_pipes;
	t_listex	**tmp;

	tmp = *result;
	n_pipes = get_n_pipes(head) + 1;
	if (ft_enewlistexarr2(&tmp, n_pipes) != 0)
		return (ERR_MALLOC);
	i = 0;
	while (i < n_pipes)
		ft_enewlistex2(tmp[i++], FALSE, TRUE);
	ret = fill_tlistx(head, &tmp);
	if (ret != ERR_OK)
		return (ret);
	i = 0;
	while (tmp[i++])
		ft_eresetnewlist(tmp[i - 1], tmp[i - 1]->size, FALSE);
	ret = fill_quotes(head, &tmp);
	if (ret != ERR_OK)
		return (ret);
	*result = tmp;
	return (SUCCESS);
}

static int	replace_empty_cmds(t_listex ***result, t_token *head, t_s *s)
{
	t_listex	**list;
	int			i;

	list = *result;
	i = 0;
	while (list[i++])
		if (ft_isemptyitem2(s, list[i - 1]->items[0]))
			if (ft_listreplace2(s, &list[i - 1]->items, "x", 0) != 0)
				return (free_result(s, &list, head, ERR_MALLOC));
	*result = list;
	return (ERR_OK);
}

int	ft_eparsermain(t_s *s, char *src, t_listex ***dst, char **envp)
{
	t_token		*head;
	t_listex	**result;

	head = NULL;
	result = NULL;
	s->ret = tokenizer(&head, src);
	if (s->ret != ERR_OK)
		return (free_tokens(&head, s->ret));
	s->ret = syntax_checker(head);
	if (s->ret != ERR_OK)
		return (free_tokens(&head, s->ret));
	s->ret = substitute_vars(s, head, envp);
	if (s->ret != ERR_OK)
		return (free_tokens(&head, s->ret));
	s->ret = remove_quotes(head);
	if (s->ret != ERR_OK)
		return (free_tokens(&head, s->ret));
	s->ret = prepare_result(&result, head);
	if (s->ret != ERR_OK)
		return (free_result(s, &result, head, s->ret));
	s->ret = replace_empty_cmds(&result, head, s);
	if (s->ret != ERR_OK)
		return (free_result(s, &result, head, s->ret));
	*dst = result;
	return (free_tokens(&head, s->ret));
}
