/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:58:11 by advorace          #+#    #+#             */
/*   Updated: 2026/03/23 22:10:58 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	else if (quote == NO_QUOTE)
	{
		if (c == '"')
			return (DOUBLE_QUOTE);
		else if (c == '\'')
			return (SINGLE_QUOTE);
	}
	return (quote);
}

int	get_string_type(char c)
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
			if (c == '<' || c == '>' || c == '|' || ft_isspace(c))
				return (end);
		}
		++end;
	}
	return (end);
}
