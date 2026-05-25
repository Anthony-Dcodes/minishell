/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_meta_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 11:23:07 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 13:01:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "macros.h"
#include "tokenizer.h"

int	assign_word_token_meta_data(t_token *token)
{
	int		quote;
	int		i;
	char	*str;

	i = 0;
	str = token->value;
	quote = NO_QUOTE;
	if (token->type != WORD)
		return (ERR_OK);
	token->meta = malloc(sizeof(t_meta) * token->len);
	if (!token->meta)
		return (ERR_MALLOC);
	while (str[i])
	{
		quote = track_quote_state(quote, str[i]);
		if (quote == NO_QUOTE)
			handle_no_quotes(token, i);
		else if (quote == SINGLE_QUOTE)
			handle_single_quotes(token, i, str[i]);
		else if (quote == DOUBLE_QUOTE)
			handle_double_quotes(token, i, str[i]);
		++i;
	}
	return (ERR_OK);
}

void	print_token_metadata(t_token *token)
{
	int	i;

	i = 0;
	printf("	Token type: %d, len: %zu\n",
		token->type, token->len);
	if (token->type == WORD)
	{
		printf("	Token metadata:\n");
		while (i < (int)token->len)
		{
			printf("		char: %c, meta: %d\n",
				token->value[i], token->meta[i]);
			++i;
		}
	}
}

void	free_metadata(t_token *head)
{
	if (head->meta)
		free(head->meta);
	return ;
}
