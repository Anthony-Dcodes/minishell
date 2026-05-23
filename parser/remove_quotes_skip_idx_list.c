/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_skip_idx_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:12:34 by advorace          #+#    #+#             */
/*   Updated: 2026/05/23 14:18:25 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"

t_skip_idxs	*create_skip_idx_node(int start_idx, int end_idx, int *ret)
{
	t_skip_idxs *new_node;

	new_node = malloc(sizeof(t_skip_idxs));
	if (!new_node)
	{
		*ret = ERR_MALLOC;
		return (NULL);
	}
	new_node->start = start_idx;
	new_node->end = end_idx;
	new_node->next = NULL;
	return (new_node);
}

void	append_skip_idx_node(t_token *head, t_skip_idxs *node)
{
	t_skip_idxs *skip_idxs_list;

	if (!head || !node)
		return ;
	if (!head->skip_idxs)
	{
		head->skip_idxs = node;
		return ;
	}
	skip_idxs_list = head->skip_idxs;
	while (skip_idxs_list->next)
		skip_idxs_list = skip_idxs_list->next;
	skip_idxs_list->next = node;
	return ;
}

void	free_skip_idx_list(t_token *head)
{
	t_skip_idxs	*temp;
	t_skip_idxs *list;

	list = head->skip_idxs;
	if (!list)
		return ;
	while (list)
	{
		temp = list->next;
		free(list);
		list = NULL;
		list = temp;
	}
	return ;
}
