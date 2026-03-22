/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:29:28 by advorace          #+#    #+#             */
/*   Updated: 2026/03/22 22:03:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int check_syntax(t_token *head)
{
	t_token *temp;
	int		previous;
	int		current;
	int		next;

	temp = head;
	while (temp)
	{
		if (temp->previous == NULL) // first node
		{
			if (temp->type == PIPE)
				return (ERR_SYNTAX);
		}
		else if (temp->next == NULL) // last node
		{
			if (temp->type == PIPE || temp->type == REDDIRECT)
				return (ERR_SYNTAX);
		}
		else // somewhere in the middle
		{
			previous = temp->previous->type;
			current = temp->type;
			next = temp->next->type;
			if (current == PIPE || current == REDDIRECT)
			{
				if (next == PIPE || next == REDDIRECT)
					return (ERR_SYNTAX);
				else if (previous == PIPE || next == PIPE)
					return (ERR_SYNTAX);
			}
		}
		if (has_unclosed_quote(temp->value))
			return (ERR_SYNTAX);
		temp = temp->next;
	}
	return (ERR_OK);
}

int has_unclosed_quote(char *str)
{
	int		i;
	int		quote_type;

	i = 0;
	quote_type = NO_QUOTE;
	while (str[i])
	{
		quote_type = track_quote_state(quote_type, str[i]);
		++i;
	}
	if (quote_type == NO_QUOTE)
		return (ERR_OK);
	return (ERR_SYNTAX);
}
