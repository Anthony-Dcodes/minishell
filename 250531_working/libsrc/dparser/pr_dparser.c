/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/06/02 09:08:32 by advorace         ###   ########.fr       */
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
#include <stdio.h>

static int	prepare_result(t_listex ***result, t_token *head)
{
	int			ret;
	int			i;
	int			n_pipes;
	t_listex	**tmp;

	tmp = *result;
	n_pipes = get_n_pipes(head) + 1;
	ft_enewlistexarr2(&tmp, n_pipes);
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

int	ft_eparsermain(t_s *s, char *src, t_listex ***dst, char **envp)
{
	int			ret;
	t_token		*head;
	t_listex	**result;

	write(1, "Hi from external parser !!\n", 27);
	head = NULL;
	ret = tokenizer(&head, src);
	if (ret != ERR_OK)
		return (ret);
	ret = syntax_checker(head);
	if (ret != ERR_OK)
		return (ret);
	ret = substitute_vars(s, head);
	if (ret != ERR_OK)
		return (ret);
	ret = remove_quotes(head);
	if (ret != ERR_OK)
		return (ret);
	ret = prepare_result(&result, head);
	if (ret != ERR_OK)
		return (ret);
	free_tokens(&head);
	*dst = result;
	return (SUCCESS);
}

