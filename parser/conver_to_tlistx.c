/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_to_tlistx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:34:07 by advorace          #+#    #+#             */
/*   Updated: 2026/05/26 10:01:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "conver_to_tlistx.h"
#include "string_utils.h"
#include "macros.h"

int	fill_tlistx(t_token *tokens, t_listex ***listex)
{
	int	n_pipes;
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	n_pipes = get_n_pipes(tokens);
	**listex = malloc(sizeof(t_listex) * (n_pipes + 1));
	if (!**listex)
		return (ERR_MALLOC);
	while (tokens)
	{
		if (tokens->type == PIPE)
		{
			++j;
			i = 0;
			continue ;
		}
		len = ft_strlen(tokens->value);
		(*listex)[j]->items[i] = malloc(len + 1);
		if (!(*listex)[j]->items[i])
			return (ERR_MALLOC);
		ft_memmove((*listex)[j]->items[i], tokens->value, len + 1);
		++i;
	}
}
