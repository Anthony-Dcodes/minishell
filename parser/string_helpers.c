/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:40:54 by advorace          #+#    #+#             */
/*   Updated: 2026/03/22 18:58:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_start_index(char *str, int start)
{
	while (str[start])
	{
		if (str[start] == ' ')
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
	int	end;
	char c;

	end = start + 1;
	if (start == -1)
		return (-1);
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
			if (c == '<' || c == '>' || c == '|' || c == ' ')
				return (end);
		}
		++end;
	}
	return (end);
}

int	get_string(int start, int end, char *src, char **dst)
{
	int	len;
	int i;

	len = end - start;
	i = 0;
	*dst = malloc(sizeof(char) * (len + 1));
	if (!*dst)
		return (ERR_MALLOC);
	while (i < len)
	{
		(*dst)[i] = src[start + i];
		++i;
	}
	(*dst)[i] = 0;
	return (ERR_OK);
}
