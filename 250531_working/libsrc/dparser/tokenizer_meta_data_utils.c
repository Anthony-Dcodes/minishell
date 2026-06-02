/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_meta_data_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:02:02 by advorace          #+#    #+#             */
/*   Updated: 2026/06/02 14:54:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "macros.h"

void	handle_no_quotes(t_token *token, int idx, char c)
{
	if (c == '\'')
		token->meta[idx] = S_QUOTE;
	else if (c == '"')
		token->meta[idx] = D_QOUTE;
	else
		token->meta[idx] = UNQOUTED_CHAR;
}

void	handle_single_quotes(t_token *token, int idx, char c)
{
	if (c == '\'')
		token->meta[idx] = S_QUOTE;
	else
		token->meta[idx] = IN_S_QUOTE;
}

void	handle_double_quotes(t_token *token, int idx, char c)
{
	if (c == '"')
		token->meta[idx] = D_QOUTE;
	else
		token->meta[idx] = IN_D_QUOTE;
}
