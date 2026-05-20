/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 22:27:52 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "macros.h"

int	tokenizer(t_token **head, char *src)
{
	int		ret;
	int		start_index;
	int		end_index;
	t_token *next_token;

	start_index = 0;
	end_index = 0;
	ret = ERR_OK;
	while (ret == ERR_OK)
	{
		next_token = get_next_token(start_index, src, &ret, &end_index);
		if (ret != ERR_OK)
			return (ret);
		if (!next_token)
			break;
		append_token(head, next_token);
		start_index = end_index;
	}
	return (ret);
}

