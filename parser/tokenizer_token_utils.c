/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:39 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 10:57:58 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "parser.h"

t_token *new_token(char *value, int	type, int quote, int *ret)
{
	t_token *node;

	node = malloc(sizeof(t_token));
	if (!node)
	{
		*ret = ERR_MALLOC;
		return (NULL);
	}
	node->type = type;
	node->quote = quote;
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
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
	temp_head->next->previous = temp_head;
	return ;
}

void	free_tokens(t_token **head)
{
	t_token *next;

	if (!head)
		return ;
	while (*head)
	{
		next = (*head)->next;
		free((*head)->value);
		free(*head);
		*head = next;
	}
}
