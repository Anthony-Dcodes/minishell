/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:21:02 by advorace          #+#    #+#             */
/*   Updated: 2026/03/26 23:01:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	remove_quotes(t_token *head)
{
	t_token	*temp;
	int		total_quotes;
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
			//printf("evaluate quote removal on: |%s|\n", str);
			i = 0;
			while (str[i])
			{
				//printf("remove quotes str[i]: %c\n", str[i]);
				if (str[i] == '\'' || str[i] == '"')
				{
					first_quote_index = i;
					second_quote_index = find_next_quote(str, i + 1, str[i]);
					if (second_quote_index == -1)
						return (ERR_SYNTAX);
					//printf("remove_quotes---\n");
					if (remove_string_quotes(str, first_quote_index, second_quote_index, &new_string) != ERR_OK)
						return (ERR_MALLOC);
					//printf("After quote removal---\n");
					free(temp->value);
					temp->value = new_string;
					str = new_string;
				}
				else
					++i;
			}
		}
		//printf("after removing quotes: |%s|\n", temp->value);
		temp = temp->next;
	}
	return (ERR_OK);
}

int	find_next_quote(char *str, int start, char quote_char)
{
	while(str[start])
	{
		if (quote_char == '"' && str[start] == '"')
			return (start);
		else if (quote_char == '\'' && str[start] == '\'')
			return (start);
		++start;
	}
	return (-1);
}

int	remove_string_quotes(char *str, int first_quote, int second_quote, char **dest)
{
	int	len;
	int	i;
	int	j;

	len = (int)ft_strlen(str);
	//printf("Allocate: %d bytes\n", len - 1);
	*dest = malloc(sizeof(char) * (len - 1));
	if (!*dest)
		return (ERR_MALLOC);
	i = 0;
	j = 0;
	while (str[i])
	{
		//printf("str[i]: %c\n", str[i]);
		if (i == first_quote || i == second_quote)
		{
			++i;
			continue;
		}
		//printf("write to dest index: %d, char: %c\n", j, str[i]);
		(*dest)[j] = str[i];
		++j;
		++i;
	}
	(*dest)[j] = 0;
	return (ERR_OK);
}
