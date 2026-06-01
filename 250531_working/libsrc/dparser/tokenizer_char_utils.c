/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:21:55 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 22:21:00 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"

int	detect_quote(char c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	else if (c == '"')
		return (DOUBLE_QUOTE);
	else
		return (NO_QUOTE);
}

int	track_quote_state(int quote, char c)
{
	if (quote == SINGLE_QUOTE)
	{
		if (c == '\'')
			return (NO_QUOTE);
	}
	else if (quote == DOUBLE_QUOTE)
	{
		if (c == '"')
			return (NO_QUOTE);
	}
	else
	{
		if (c == '"')
			return (DOUBLE_QUOTE);
		else if (c == '\'')
			return (SINGLE_QUOTE);
		return (NO_QUOTE);
	}
	return (quote);
}

int	get_token_type(char c)
{
	if (c == '\'' || c == '"')
		return (WORD);
	else if (c == '|')
		return (PIPE);
	else if (c == '<' || c == '>')
		return (REDDIRECT);
	else if (c == '\0')
		return (END_FILE);
	return (WORD);
}

char	quote_to_char(int quote)
{
	if (quote == NO_QUOTE)
		return (0);
	else if (quote == SINGLE_QUOTE)
		return ('\'');
	else
		return ('"');
}
