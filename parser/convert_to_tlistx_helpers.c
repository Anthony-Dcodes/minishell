/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_to_tlistx_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:37:31 by advorace          #+#    #+#             */
/*   Updated: 2026/05/26 09:47:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

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
