/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/03/16 22:52:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//echo a b | echo c
int	lexer(t_tokens **tokens, char *src)
{
	int	i;
	int	str_end;

	i = 0;
	str_end = 0;
	*tokens = malloc(sizeof(t_tokens));
	if (!*tokens)
		return (ERR_MALLOC);
	while (!str_end)
	{
		//while (src[i] != ' ')
		//	++i;
	}
}

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
}

int find_end_index(char *str, int start, t_tokens *tokens)
{
	int	end;

	end = start + 1;
	while (str[end])
	{
		if (tokens->quote == SINGLE_QUOTE)
			if (str[end] == '\'')
				return (end);
		else if (tokens->quote == DOUBLE_QUOTE)
			if (str[end] == '"')
				return (end);
		else if (tokens->quote == NO_QUOTE)
			if (str[end] == ' ')
				return (end);
		++end;
	}
	return (ERR_SYNTAX);
}
