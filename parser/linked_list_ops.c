/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:39 by advorace          #+#    #+#             */
/*   Updated: 2026/03/17 21:39:48 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token *new_token(char *value, int	is_pipe, int quote, int *ret)
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		ret = ERR_MALLOC;
		return ;
	}
	new_token->is_pipe = is_pipe;
	new_token->quote = quote;
	new_token->value = value;
	new_token->next = NULL;
	return (new_token);
}

void	append_token(t_token **head, t_token *new)
{
	t_token *temp_head;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp_head = *head;
	while (temp_head->next)
		temp_head = temp_head->next;
	temp_head->next = new;
	return ;
}
