/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:21:02 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 10:25:20 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>
#include "remove_quotes.h"

int	remove_quotes(t_token *head)
{
	t_token	*temp;
	//int		total_quotes;
	int		i;
	char	*str;
	int		first_quote_index;
	int		second_quote_index;
	char	*new_string;

	temp = head;
	while (temp)
	{
		if (temp->type == WORD)
		{
			str = temp->value;
			i = 0;
			while (str[i])
			{
				if ((str[i] == '\'' || str[i] == '"')
					&& temp->meta[i] != EXPANSION)
				{
					first_quote_index = i;
					second_quote_index = find_next_quote(str, i + 1, str[i], temp);
					if (second_quote_index == -1)
						return (ERR_SYNTAX);
					if (remove_string_quotes(str, first_quote_index, second_quote_index, &new_string, temp) != ERR_OK)
						return (ERR_MALLOC);
					free(temp->value);
					temp->value = new_string;
					str = new_string;
					i = second_quote_index - 1;
				}
				else
					++i;
			}
		}
		temp = temp->next;
	}
	return (ERR_OK);
}


int	find_next_quote(char *str, int start, char quote_char, t_token *head)
{
	while(str[start])
	{
		if (head->meta[start] == EXPANSION)
		{
			++start;
			continue;
		}
		if (quote_char == '"' && str[start] == '"')
			return (start);
		else if (quote_char == '\'' && str[start] == '\'')
			return (start);
		++start;
	}
	return (-1);
}

int	remove_string_quotes(char *str, int first_quote, int second_quote, char **dest, t_token *head)
{
	int	len;
	int	i;
	int	j;
	t_meta	*new_meta;

	len = (int)ft_strlen(str);
	*dest = malloc(sizeof(char) * (len - 1));
	new_meta = malloc(sizeof(t_meta) * (len - 2));
	if (!*dest || !new_meta)
		return (ERR_MALLOC);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == first_quote || i == second_quote)
		{
			++i;
			continue;
		}
		(*dest)[j] = str[i];
		new_meta[j] = head->meta[i];
		++j;
		++i;
	}
	(*dest)[j] = 0;
	free(head->meta);
	head->meta = new_meta;
	return (ERR_OK);
}
