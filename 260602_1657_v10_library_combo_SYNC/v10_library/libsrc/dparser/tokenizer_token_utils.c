/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_token_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:39 by advorace          #+#    #+#             */
/*   Updated: 2026/06/03 12:46:35 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tokenizer.h"
#include "remove_quotes.h"
#include "string_utils.h"

t_token	*create_new_token(char *value, int type, int quote, int *ret)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
	{
		*ret = ERR_MALLOC;
		free(value);
		return (NULL);
	}
	node->type = type;
	node->quote = quote;
	node->value = value;
	node->len = ad_strlen(value);
	node->next = NULL;
	node->previous = NULL;
	node->meta = NULL;
	if (node->type == WORD)
		*ret = assign_word_token_meta_data(node);
	return (node);
}

void	append_token(t_token **head, t_token *token)
{
	t_token	*temp_head;

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

int	free_tokens(t_token **head, int ret)
{
	t_token	*next;

	if (*head == NULL)
		return (ret);
	while (*head)
	{
		next = (*head)->next;
		free_token(*head, ERR_OK);
		*head = next;
	}
	return (ret);
}

t_token	*get_next_token(int start_index, char *src, int *ret, int *end_index)
{
	int		quote;
	int		token_type;
	char	*string;
	t_token	*token;

	start_index = find_start_index(src, start_index);
	if (start_index == -1)
		return (NULL);
	quote = detect_quote(src[start_index]);
	token_type = get_token_type(src[start_index]);
	*end_index = find_end_index(src, start_index, quote);
	*ret = get_string(start_index, *end_index, src, &string);
	if (*ret != ERR_OK)
		return (NULL);
	token = create_new_token(string, token_type, quote, ret);
	return (token);
}

int	free_token(t_token *token, int ret)
{
	if (token == NULL)
		return (ret);
	free(token->value);
	free_metadata(token);
	free(token);
	return (ret);
}
