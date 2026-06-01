/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:34:07 by advorace          #+#    #+#             */
/*   Updated: 2026/06/01 18:08:15 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "convert_to_tlistx.h"
#include "string_utils.h"
#include "macros.h"
#include "tokenizer.h"
#include "pr_dparser.h"
#include <stdio.h>

int	fill_tlistx(t_token *tokens, t_listex ***listex)
{
	int		j;
	int		ret;
	t_token *cur;

	j = 0;
	ret = ERR_OK;
	set_attr_to_null(tokens, listex);
	cur = tokens;
	while (cur)
	{
		if (cur->type == PIPE)
			j++;
		else
			ft_elistaddex2((*listex)[j], cur->value);
		cur = cur->next;
	}
	memset_attr(tokens, *listex);
	ret = fill_quotes(tokens, listex);
	return (ret);
}

int	fill_quotes(t_token *tokens, t_listex ***listex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens)
	{
		if (tokens->type == PIPE)
		{
			i++;
			j = 0;
		}
		else
			(*listex)[i]->xattr_qc[j++] = quote_to_char(tokens->quote);
		tokens = tokens->next;
	}
	return (ERR_OK);
}

void	set_attr_to_null(t_token *head, t_listex ***result)
{
	int	n_pipes;
	int	i;

	n_pipes = get_n_pipes(head) + 1;
	ft_enewlistexarr2(result, n_pipes);
	i = 0;
	while (i < n_pipes)
	{
		(*result)[i]->items = NULL;
		(*result)[i]->size = 0;
		(*result)[i]->xattr_qc = NULL;
		(*result)[i]->xattr_sc = NULL;
		(*result)[i]->xattr_pc = NULL;
		(*result)[i]->xattr_pidx = NULL;
		(*result)[i]->xattr_rc = NULL;
		i++;
	}
}

void	memset_attr(t_token *head, t_listex **result)
{
	int	i;
	int	j;

	printf("ready pipes : %i\n", get_n_pipes(head) + 1);
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
			printf("ready %i, %i(%lu) : %s\n", i, j - 1,
				result[i]->size, result[i]->items[j - 1]);
		i++;
	}
}
