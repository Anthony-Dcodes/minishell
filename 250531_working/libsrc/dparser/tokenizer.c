/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:08:51 by advorace          #+#    #+#             */
/*   Updated: 2026/06/02 12:07:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tokenizer.h"
#include "macros.h"
#include "string_utils.h"

int	tokenizer(t_token **head, char *src)
{
	int		ret;
	int		start_index;
	int		end_index;
	t_token	*next_token;

	start_index = 0;
	end_index = 0;
	ret = ERR_OK;
	while (ret == ERR_OK)
	{
		next_token = get_next_token(start_index, src, &ret, &end_index);
		if (ret != ERR_OK)
			return (ret);
		if (!next_token)
			break ;
		//print_token_metadata(next_token);
		append_token(head, next_token);
		ret = add_spaces(head);
		if (ret != ERR_OK)
			return (ret);
		start_index = end_index;
	}
	return (ret);
}

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
		if (temp->previous == NULL || temp->previous->type == PIPE
			|| temp->next == NULL || temp->next->type == PIPE
			|| temp->type == PIPE)
		{
			temp = temp->next;
			continue ;
		}
		if (create_extra_spaced_str(&extra_space, temp) != ERR_OK)
			return (ERR_MALLOC);
		assing_tokens_and_free(&bef, &aft, &temp);
		temp = create_new_token(extra_space, WORD, detect_quote(extra_space[0]), &ret);
		if (ret != ERR_OK)
			return (ret);
		reassing_tokens_and_advance(&bef, &aft, &temp);
	}
	return (ERR_OK);
}

int create_extra_spaced_str(char **str, t_token *token)
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

void	assing_tokens_and_free(t_token **bef, t_token **aft, t_token **temp)
{
	*bef = (*temp)->previous;
	*aft = (*temp)->next;
	free_token(*temp);
}

void	reassing_tokens_and_advance(t_token **bef, t_token **aft, t_token **temp)
{
	(*bef)->next = *temp;
	(*temp)->next = *aft;
	(*temp) = (*temp)->next;
}
