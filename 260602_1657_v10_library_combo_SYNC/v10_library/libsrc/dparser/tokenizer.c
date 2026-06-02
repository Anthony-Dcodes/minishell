/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/06/02 14:19:07 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tokenizer.h"
#include "macros.h"
#include "string_utils.h"

int	tokenizer(t_token **head, char *src)
{
	int		ret;
	int		start_index;
	int		end_index;
	t_token	*next_token;

	start_index = 0;
	end_index = 0;
	ret = ERR_OK;
	while (ret == ERR_OK)
	{
		next_token = get_next_token(start_index, src, &ret, &end_index);
		if (ret != ERR_OK)
			return (ret);
		if (!next_token)
			break ;
		append_token(head, next_token);
		ret = add_spaces(head);
		if (ret != ERR_OK)
			return (ret);
		start_index = end_index;
	}
	return (ret);
}
