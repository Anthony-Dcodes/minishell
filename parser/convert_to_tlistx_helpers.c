/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:37:31 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 18:16:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "string_utils.h"
#include "tokenizer.h"
#include "convert_to_tlistx.h"

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
	//printf("quote int: %d translated str: %c\n", quote, quote_to_char(quote));
	if (!listex->xattr_qc)
	{
		listex->xattr_qc = new_quote;
		return (ERR_OK);
	}
	new_xattr_qc = ft_strjoin(listex->xattr_qc, new_quote);
	free(new_quote);
	if (!new_xattr_qc)
		return (ERR_MALLOC);
	free(listex->xattr_qc);
	listex->xattr_qc = new_xattr_qc;
	return (ERR_OK);
}

int	allocate_t_listex_mem(t_listex ***listex, t_token *head)
{
	int	n_pipes;
	int	i;
	int	n_strings_to_malloc;

	i = 0;
	n_pipes = get_n_pipes(head);
	*listex = malloc(sizeof(t_listex*) * (n_pipes + 2));
	if (!*listex)
		return (ERR_MALLOC);
	while (i < n_pipes + 1)
	{
		(*listex)[i] = malloc(sizeof(t_listex));
		if (!(*listex)[i])
			return (ERR_MALLOC);
		n_strings_to_malloc = get_n_tokens_before_next_pipe(head, i + 1);
		(*listex)[i]->items = malloc(sizeof(char *) * n_strings_to_malloc);
		if (!(*listex)[i]->items)
			return (ERR_MALLOC);
		++i;
	}
	(*listex)[i] = NULL;
	return (ERR_OK);
}

int	assing_string(t_listex *listex, char *str, int i)
{
	int	len;

	len = ft_strlen(str);
	listex->items[i] = malloc(len + 1);
	if (!listex->items[i])
		return (ERR_MALLOC);
	ft_memmove(listex->items[i], str, len + 1);
	return (ERR_OK);
}

void assign_size(t_listex *listex, int size)
{
	size_t new_size;

	new_size = (size_t)size;
	listex->size = new_size;
}

int	get_n_tokens_before_next_pipe(t_token *head, int nth_pipe)
{
	int	n_tokens;
	int	n_pipes;

	n_pipes = 0;
	n_tokens = 0;
	while (head)
	{
		if (n_pipes == nth_pipe - 1 && head->type != PIPE)
			++n_tokens;
		if (head->type == PIPE)
			++n_pipes;
		head = head->next;
	}
	//printf("N_tokens: %d, before pipe: %d\n", n_tokens, nth_pipe);
	return (n_tokens);
}
