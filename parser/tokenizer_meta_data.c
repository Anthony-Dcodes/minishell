/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_meta_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:23:07 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 10:25:20 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "macros.h"
#include "tokenizer.h"

int	assign_word_token_meta_data(t_token *token)
{
	int	quote;
	int	i;
	char	*str;

	i = 0;
	str = token->value;
	quote = NO_QUOTE;
	if (token->type != WORD)
	{
		token->meta = NULL;
		return (ERR_OK);
	}
	token->meta = malloc(sizeof(t_meta) * token->len);
	if (!token->meta)
		return (ERR_MALLOC);
	while (str[i])
	{
		quote = track_quote_state(quote, str[i]);
		if (quote == NO_QUOTE)
		{	if (str[i] == '\'')
				token->meta[i] = S_QUOTE;
			else if (str[i] == '"')
				token->meta[i] = D_QOUTE;
			else
				token->meta[i] = UNQOUTED_CHAR;
		}
		else if (quote == SINGLE_QUOTE)
		{
			if (str[i] == '\'')
				token->meta[i] = S_QUOTE;
			else
				token->meta[i] = IN_S_QUOTE;
		}
		else if (quote == DOUBLE_QUOTE)
		{
			if (str[i] == '"')
				token->meta[i] = D_QOUTE;
			else
				token->meta[i] = IN_D_QUOTE;
		}
		++i;
	}
	return (ERR_OK);
}

void print_token_metadata(t_token *token)
{
	int i;

	i = 0;
	printf("	Token type: %d, len: %zu\n", token->type, token->len);
	if (token->type == WORD)
	{
		printf("	Token metadata:\n");
		while (i < (int)token->len)
		{
			printf("		char: %c, meta: %d\n", token->value[i], token->meta[i]);
			++i;
		}
	}
}

void free_metadata(t_token *head)
{
	if (head->meta)
		free(head->meta);
	return ;
}

