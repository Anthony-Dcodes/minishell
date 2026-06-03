/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:48:14 by advorace          #+#    #+#             */
/*   Updated: 2026/06/03 12:49:56 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "macros.h"
#include "tokenizer.h"

void	free_metadata(t_token *head)
{
	if (head->meta)
		free(head->meta);
	return ;
}

int	free_tokens(t_token **head, int ret)
{
	t_token	*next;

	if (*head == NULL)
		return (ret);
	while (*head)
	{
		next = (*head)->next;
		free_token(*head, ERR_OK);
		*head = next;
	}
	return (ret);
}

int	free_token(t_token *token, int ret)
{
	if (token == NULL)
		return (ret);
	free(token->value);
	free_metadata(token);
	free(token);
	return (ret);
}
