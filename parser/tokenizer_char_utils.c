/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:21:55 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 11:27:55 by advorace         ###   ########.fr       */
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
			return(NO_QUOTE);
	}
	else
	{
		if (c == '"')
			return (DOUBLE_QUOTE);
		else if (c == '\'')
			return (SINGLE_QUOTE);
	}
}

int	get_char_type(char c)
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
