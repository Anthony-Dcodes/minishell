/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:37:31 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 12:44:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "string_utils.h"
#include "tokenizer.h"

int	get_n_pipes(t_token *head)
{
	int		n_pipes;

	n_pipes = 0;
	while (head)
	{
		if (head->type == PIPE)
			++n_pipes;
		head = head->next;
	}
	return (n_pipes);
}

int	assign_quote(t_listex *listex, int quote)
{
	char	*new_quote;
	char	*new_xattr_qc;

	new_quote = malloc(2 * sizeof(char));
	if (!new_quote)
		return (ERR_MALLOC);
	new_quote[0] = quote_to_char(quote);
	new_quote[1] = '\0';
	if (!listex->xattr_qc)
		new_xattr_qc = ft_strdup(new_quote);
	else
	{
		new_xattr_qc = ft_strjoin(listex->xattr_qc, new_quote);
		free(listex->xattr_qc);
	}
	if (!new_xattr_qc)
	{
		free(new_quote);
		return (ERR_MALLOC);
	}
	listex->xattr_qc = new_xattr_qc;
	free(new_quote);
	return (ERR_OK);
}

int	allocate_t_listex_mem(t_listex ***listex, t_token *head)
{
	int	n_pipes;
	int	i;

	i = 0;
	n_pipes = get_n_pipes(head);
	*listex = malloc(sizeof(t_listex*) * (n_pipes + 2));
	if (!*listex)
		return (ERR_MALLOC);
	while (i < n_pipes)
	{
		(*listex)[i] = malloc(sizeof(t_listex));
		if (!(*listex)[i])
		{
			return (ERR_MALLOC);
		}
		++i;
	}
	(*listex)[i] = NULL;
	return (ERR_OK);
}
