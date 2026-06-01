/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/05/31 18:06:53 by oem5491          ###   ########.fr       */
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
	t_token 	*head;
	t_listex	**result;
	int			i;
	int			j;
	int			n_pipes;
	
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
	///// TBD
			n_pipes = get_n_pipes(head) + 1;
			ft_enewlistexarr2(&result, n_pipes);
			i = 0;
			while (i < n_pipes)
			{
				result[i]->items = NULL;
				result[i]->size = 0;
				result[i]->xattr_qc = NULL;
				result[i]->xattr_sc = NULL;
				result[i]->xattr_pc = NULL;
				result[i]->xattr_pidx = NULL;
				result[i]->xattr_rc = NULL;
				i++;
			}
	///// TBD
	ret = fill_tlistx(head, &result);
	if (ret != ERR_OK)
		return (ret);
	///// TBD
			printf("ready pipes : %i\n", n_pipes);
			i = 0;
			j = 0;
			while (result[i])
			{
				result[i]->xattr_qc = malloc(sizeof(char) * (result[i]->size));
				result[i]->xattr_sc = malloc(sizeof(char) * (result[i]->size));
				result[i]->xattr_pc = malloc(sizeof(char) * (result[i]->size));
				result[i]->xattr_pidx = malloc(sizeof(char) * (result[i]->size));
				result[i]->xattr_rc = malloc(sizeof(char) * (result[i]->size));
				ft_ememset(result[i]->xattr_qc, 0, result[i]->size);
				ft_ememset(result[i]->xattr_sc, 0, result[i]->size);
				ft_ememset(result[i]->xattr_pc, 0, result[i]->size);
				ft_ememset(result[i]->xattr_pidx, 0, result[i]->size);
				ft_ememset(result[i]->xattr_rc, 0, result[i]->size);
				j = 0;
				while (j++ < result[i]->size)
					printf("ready %i, %i(%lu) : %s\n", i, j - 1, result[i]->size, result[i]->items[j - 1]);
				i++;
			}
	///// TBD
	ret = fill_quotes(head, &result);
	if (ret != ERR_OK)
		return (ret);
	free_tokens(&head);
	*dst = result;
	return (SUCCESS);
}

