/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:34:07 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 18:36:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "convert_to_tlistx.h"
#include "string_utils.h"
#include "macros.h"

#include <stdio.h>
int	fill_tlistx(t_token *tokens, t_listex ***listex)
{
	int	i;
	int	j;
	int ret;

	i = 0;
	j = 0;
	ret = allocate_t_listex_mem(listex, tokens);
	if (ret != ERR_OK)
		return (ret);
	while (tokens)
	{
		if (i == 0)
			(*listex)[j]->xattr_qc = NULL;
		if (tokens->type == PIPE)
		{
			++j;
			i = 0;
			tokens = tokens->next;
			continue ;
		}
		assign_size((*listex)[j], i + 1);
		assing_string((*listex)[j], tokens->value, i);
		assign_quote((*listex)[j], tokens->quote);
		tokens = tokens->next;
		++i;
	}
	return (ERR_OK);
}
