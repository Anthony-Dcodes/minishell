/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:39 by advorace          #+#    #+#             */
/*   Updated: 2026/03/17 23:11:20 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token *new_token(char *value, int	is_pipe, int quote, int *ret)
{
	t_token *node;

	node = malloc(sizeof(t_token));
	if (!node)
	{
		*ret = ERR_MALLOC;
		return (NULL);
	}
	node->is_pipe = is_pipe;
	node->quote = quote;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	append_token(t_token **head, t_token *token)
{
	t_token *temp_head;

	if (*head == NULL)
	{
		*head = token;
		return ;
	}
	temp_head = *head;
	while (temp_head->next)
		temp_head = temp_head->next;
	temp_head->next = token;
	return ;
}
