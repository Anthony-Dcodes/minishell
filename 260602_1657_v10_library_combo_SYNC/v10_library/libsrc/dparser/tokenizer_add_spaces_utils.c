/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_add_spaces_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:07 by advorace          #+#    #+#             */
/*   Updated: 2026/06/03 12:39:44 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "macros.h"
#include "tokenizer.h"

void	assing_tokens_and_free(t_token **bef, t_token **aft, t_token **temp)
{
	*bef = (*temp)->previous;
	*aft = (*temp)->next;
	free_token(*temp, ERR_OK);
}

void	reassing_tokens_and_advance(t_token **bef,
		t_token **aft, t_token **temp)
{
	(*bef)->next = *temp;
	(*temp)->next = *aft;
	(*temp)->previous = *bef;
	(*aft)->previous = *temp;
	(*temp) = (*temp)->next;
}

int	relink_tokens(t_token **bef, t_token **aft, t_token **temp, int ret)
{
	(*bef)->next = *aft;
	(*aft)->previous = *bef;
	return(free_token(*temp, ret));
}
