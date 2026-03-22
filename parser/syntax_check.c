/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:29:28 by advorace          #+#    #+#             */
/*   Updated: 2026/03/22 22:24:47 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int check_syntax(t_token *head)
{
	t_token *temp;
	int		current_type;

	temp = head;
	while (temp)
	{
		current_type = temp->type;
		if (current_type == REDDIRECT)
		{
			if (temp->next == NULL)
				return (ERR_SYNTAX);
			else if (temp->next->type != WORD)
				return (ERR_SYNTAX);
		}
		else if (current_type == PIPE)
		{
			if (temp->previous == NULL)
				return (ERR_SYNTAX);
			else if (temp->previous->type != WORD)
				return (ERR_SYNTAX);
			else if (temp->next == NULL)
				return (ERR_SYNTAX);
			else if (temp->next->type != WORD)
				return (ERR_SYNTAX);
		}
		else if (current_type == WORD)
		{
			if (has_unclosed_quote(temp->value))
				return (ERR_SYNTAX);
		}
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
