/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_token_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:39 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 22:35:56 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "tokenizer.h"

t_token *create_new_token(char *value, int	type, int quote, int *ret)
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

t_token	*get_next_token(int start_index, char *src, int *ret, int *end_index)
{
	int		quote;
	int		char_type;
	char	*string;
	t_token	*token;

	start_index = find_start_index(src, start_index);
	if (start_index == -1)
		return (NULL);
	quote = detect_quote(src[start_index]);
	char_type = get_char_type(src[start_index]);
	*end_index = find_end_index(src, start_index, quote);
	*ret = get_string(start_index, *end_index, src, &string);
	if (*ret != ERR_OK)
		return (NULL);
	token = create_new_token(string, char_type, quote, ret);
	return (token);
}
