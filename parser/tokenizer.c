/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 11:00:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	tokenizer(t_token **head, char *src)
{
	int	ret;
	int	start_index;
	int	end_index;
	char	*string;
	int		quote;
	int		string_type;
	t_token *token;

	start_index = 0;
	ret = ERR_OK;
	while (ret == ERR_OK)
	{
		start_index = find_start_index(src, start_index);
		if (start_index == -1)
			break;
		quote = detect_quote(src[start_index]);
		string_type = get_string_type(src[start_index]);
		end_index = find_end_index(src, start_index, quote);
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

