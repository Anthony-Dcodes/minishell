/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/03/22 19:54:06 by advorace         ###   ########.fr       */
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
	int		string_type;
	t_token *token;

	start_index = 0;
	ret = ERR_OK;
	str_end = 0;
	while (!str_end && ret == ERR_OK)
	{
		if (start_index == -1)
			break;
		start_index = find_start_index(src, start_index);
		quote = detect_quote(src[start_index]);
		string_type = get_string_type(src[start_index]);
		end_index = find_end_index(src, start_index, quote);
		//printf("start index: %d, quote: %d, string type: %d, end_index: %d\n", start_index, quote, string_type, end_index);
		if (end_index == -1 && start_index == -1 )
			break;
		ret = get_string(start_index, end_index, src, &string);
		if (ret != ERR_OK)
			return (ret);
		token = new_token(string, string_type, quote, &ret);
		if (ret != ERR_OK)
			return (ret);
		append_token(head, token);
		start_index = end_index;
	}
	return (ret);
}

