/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_string_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:58:11 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 22:34:00 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"
#include "parser.h"
#include "tokenizer.h"

int	find_start_index(char *str, int start)
{
	while (str[start])
	{
		if (ft_isspace(str[start]))
		{
			++start;
			continue;
		}
		return (start);
	}
	return (-1);
}

// Return last index of the string (exclusive)
int find_end_index(char *str, int start, int quote)
{
	int		end;
	char	c;

	end = start + 1;
	if (str[start] == '|')
		return (end);
	if (str[start] == '<' || str[start] == '>')
	{
		if (str[start] == str[end] && str[end])
			return (end + 1);
		return (end);
	}
	while (str[end])
	{
		c = str[end];
		quote = track_quote_state(quote, c);
		if (quote == NO_QUOTE)
		{
			if (c == '<' || c == '>' || c == '|' || ft_isspace(c))
				return (end);
		}
		++end;
	}
	return (end);
}
