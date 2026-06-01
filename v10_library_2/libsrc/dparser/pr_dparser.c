/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/06/01 16:53:42 by advorace         ###   ########.fr       */
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

int	ft_eparsermain(t_s *s, char *src, t_listex ***dst, char **envp)
{
	int			ret;
	t_token		*head;
	t_listex	**result;

	write(1, "Hi from external parser_!\n", 26);
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
	ret = fill_tlistx(head, &result);
	if (ret != ERR_OK)
		return (ret);
	free_tokens(&head);
	*dst = result;
	return (SUCCESS);
}
