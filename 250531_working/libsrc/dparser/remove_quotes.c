/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:21:02 by advorace          #+#    #+#             */
/*   Updated: 2026/06/02 15:11:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "remove_quotes.h"
#include "string_utils.h"

int	remove_quotes(t_token *head)
{
	t_token	*temp;
	int		i;

	temp = head;
	while (temp)
	{
		if (temp->type == WORD)
		{
			i = 0;
			while (temp->value[i])
			{
				if ((temp->value[i] == '\'' || temp->value[i] == '"')
					&& temp->meta[i] != EXPANSION)
				{
					if (find_and_remove_next_quote(temp, &i) != ERR_OK)
						return (ERR_MALLOC);
				}
				else
					++i;
			}
		}
		temp = temp->next;
	}
	return (ERR_OK);
}

int	find_and_remove_next_quote(t_token *temp, int *i)
{
	int		first_quote_index;
	int		second_quote_index;
	char	*new_string;

	first_quote_index = *i;
	second_quote_index = find_next_quote(temp->value, *i + 1,
			temp->value[*i], temp);
	if (second_quote_index == -1)
		return (ERR_SYNTAX);
	if (remove_string_quotes(first_quote_index, second_quote_index,
			&new_string, temp) != ERR_OK)
		return (ERR_MALLOC);
	free(temp->value);
	temp->value = new_string;
	*i = second_quote_index - 1;
	return (ERR_OK);
}

int	find_next_quote(char *str, int start, char quote_char, t_token *head)
{
	while (str[start])
	{
		if (head->meta[start] == EXPANSION)
		{
			++start;
			continue ;
		}
		if (quote_char == '"' && str[start] == '"')
			return (start);
		else if (quote_char == '\'' && str[start] == '\'')
			return (start);
		++start;
	}
	return (-1);
}

int	remove_string_quotes(int first_quote, int second_quote,
		char **dest, t_token *head)
{
	int		i;
	int		j;
	t_meta	*new_meta;

	i = 0;
	j = 0;
	if (alloc_dest_new_meta(head, dest, &new_meta) != ERR_OK)
		return (ERR_MALLOC);
	while (head->value[i])
	{
		if (i == first_quote || i == second_quote)
		{
			++i;
			continue ;
		}
		(*dest)[j] = head->value[i];
		new_meta[j] = head->meta[i];
		++j;
		++i;
	}
	(*dest)[j] = 0;
	free(head->meta);
	head->meta = new_meta;
	head->len = ad_strlen(*dest);
	return (ERR_OK);
}

int	alloc_dest_new_meta(t_token *head, char **dest, t_meta **new_meta)
{
	int	len;

	len = (int)ad_strlen(head->value);
	*dest = malloc(sizeof(char) * (len - 1));
	*new_meta = malloc(sizeof(t_meta) * (len - 2));
	if (!*dest || !*new_meta)
		return (ERR_MALLOC);
	return (ERR_OK);
}
