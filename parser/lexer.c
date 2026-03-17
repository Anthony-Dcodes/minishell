/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/03/17 21:40:50 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//echo a b | echo c
int	lexer(t_token **head, char *src)
{
	int	ret;
	int	start_index;
	int	end_index;
	int	str_end;
	char	*string;
	int		quote;
	int		pipe;
	t_token *token;

	start_index = 0;
	ret = ERR_OK;
	str_end = 0;
	while (!str_end && ret == ERR_OK)
	{
		start_index = find_start_index(src, start_index);
		if (start_index == -1)
			str_end = 1;
		quote = detect_quote(src[start_index]);
		pipe = detect_pipe(src[start_index]);
		end_index = find_end_index(src, start_index, quote);
		if (end_index == -1)
			str_end = 1;
		if (end_index == -2)
			return (ERR_SYNTAX);
		ret = get_string(start_index, end_index, src, &string);
		if (ret != ERR_OK)
			return (ret);
		token = new_token(string, pipe, quote, &ret);
		if (ret != ERR_OK)
			return (ret);
		append_token(head, token);
		start_index = end_index;
	}
	return (ret);
}

