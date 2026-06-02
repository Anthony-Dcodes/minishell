/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx_helpers2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:54:33 by advorace          #+#    #+#             */
/*   Updated: 2026/06/01 14:56:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "structs.h"
#include <stdio.h>

void	assign_size(t_listex *listex, int size)
{
	size_t	new_size;

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
	return (n_tokens);
}

void	print_t_listex(t_listex ***head)
{
	t_listex	**listex;
	int			x;
	int			y;

	x = 0;
	y = 0;
	listex = *head;
	while (listex[x])
	{
		y = 0;
		printf("listx[%d]\n", x);
		while (y < (int)listex[x]->size)
		{
			printf("	items[%d]: %30s, quotes int/char: [%d/%c]\n",
				y, listex[x]->items[y], listex[x]->xattr_qc[y],
				listex[x]->xattr_qc[y]);
			++y;
		}
		printf("	listx size: %zu\n", listex[x]->size);
		++x;
	}
}
