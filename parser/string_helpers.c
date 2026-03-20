/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:40:54 by advorace          #+#    #+#             */
/*   Updated: 2026/03/20 18:55:30 by advorace         ###   ########.fr       */
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

	end = start + 1;
	if (start == -1)
		return (-1);
	while (str[end])
	{
		if (quote == SINGLE_QUOTE || quote == DOUBLE_QUOTE)
		{
			if (str[end] == '"' || str[end] == '\'')
				quote = NO_QUOTE;
		}
		else if (quote == NO_QUOTE)
		{
			if (str[end] == ' ')
				return (end);
			else if (str[end] == '"' || str[end] == '\'')
				quote = SINGLE_QUOTE;
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

int	detect_quote(char c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	else if (c == '"')
		return (DOUBLE_QUOTE);
	else
		return (NO_QUOTE);
}

int	detect_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}
