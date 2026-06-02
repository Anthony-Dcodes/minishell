/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_string_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:58:11 by advorace          #+#    #+#             */
/*   Updated: 2026/06/02 09:00:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"
#include "string_utils.h"
#include "tokenizer.h"

int	find_start_index(char *str, int start)
{
	while (str[start])
	{
		if (ad_isspace(str[start]))
		{
			++start;
			continue ;
		}
		return (start);
	}
	return (-1);
}

// Return last index of the string (exclusive)
int	find_end_index(char *str, int start, int quote)
{
	int		end;
	char	c;

	end = start + 1;
	c = str[start];
	if (c == '|' || c == '<' || c == '>')
	{
		if (c == str[end] && (c != '|'))
			return (end + 1);
		return (end);
	}
	while (str[end])
	{
		c = str[end];
		if (quote == NO_QUOTE && (c == '\'' || c == '"'))
			return (end);
		quote = track_quote_state_v2(quote, c);
		if (quote == NO_QUOTE
			&& (c == '<' || c == '>' || c == '|' || ad_isspace(c)))
			return (end);
		else if (quote == END_QUOTE)
			return (end + 1);
		++end;
	}
	return (end);
}
