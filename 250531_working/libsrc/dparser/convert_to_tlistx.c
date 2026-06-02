/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:34:07 by advorace          #+#    #+#             */
/*   Updated: 2026/06/02 09:38:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "convert_to_tlistx.h"
#include "string_utils.h"
#include "macros.h"
#include "tokenizer.h"
#include "pr_dparser.h"

int	fill_tlistx(t_token *tokens, t_listex ***listex)
{
	int	j;
	int	ret;

	j = 0;
	while (tokens)
	{
		if (tokens->type == PIPE)
			j++;
		else
			ft_elistaddex2((*listex)[j], tokens->value);
		tokens = tokens->next;
	}
	return (ERR_OK);
}

int	fill_quotes(t_token *tokens, t_listex ***listex)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	while (tokens)
	{
		if (tokens->type == PIPE)
		{
			i++;
			j = 0;
		}
		else
			(*listex)[i]->xattr_qc[j++] = quote_to_char(tokens->quote);
		tokens = tokens->next;
	}
	return (ERR_OK);
}
