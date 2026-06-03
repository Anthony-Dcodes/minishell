/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_add_spaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:18:12 by advorace          #+#    #+#             */
/*   Updated: 2026/06/03 12:39:40 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "macros.h"
#include "tokenizer.h"
#include "string_utils.h"

int	add_spaces(t_token **head)
{
	t_token	*temp;
	t_token	*bef;
	t_token	*aft;
	char	*extra_space;
	int		ret;

	temp = *head;
	while (temp)
	{
		if (not_valid_add_spaces_token(temp))
		{
			temp = temp->next;
			continue ;
		}
		if (create_extra_spaced_str(&extra_space, temp) != ERR_OK)
			return (ERR_MALLOC);
		assing_tokens_and_free(&bef, &aft, &temp);
		temp = create_new_token(extra_space, WORD,
				detect_quote(extra_space[0]), &ret);
		if (ret != ERR_OK)
			return (relink_tokens(&bef, &aft, &temp, ret));
		reassing_tokens_and_advance(&bef, &aft, &temp);
	}
	return (ERR_OK);
}

int	create_extra_spaced_str(char **str, t_token *token)
{
	size_t	len;

	len = ad_strlen(token->value);
	*str = malloc(sizeof(char) * (len + 2));
	if (!*str)
		return (ERR_MALLOC);
	ad_memmove(*str, token->value, len);
	(*str)[len] = ' ';
	(*str)[len + 1] = '\0';
	return (ERR_OK);
}

int	not_valid_add_spaces_token(t_token *token)
{
	if (token->previous == NULL)
		return (1);
	if (token->next == NULL)
		return (1);
	return (token->previous->type == PIPE
		|| token->next->type == PIPE
		|| token->type == PIPE);
}
