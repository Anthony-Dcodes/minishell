/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:38:41 by advorace          #+#    #+#             */
/*   Updated: 2026/03/23 23:11:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	substitute_vars(t_token *head)
{
	t_token *temp;
	char	*str;
	int		i;
	int		quote;
	int		end_index;

	temp = head;
	while (temp)
	{
		i = 0;
		if (temp->type == WORD)
		{
			str = temp->value;
			quote = NO_QUOTE;
			while(str[i])
			{
				quote = track_quote_state(quote, str[i]);
				if (quote == NO_QUOTE || quote == DOUBLE_QUOTE)
				{
					if (str[i] == '$')
					{
						if (str[i + 1] == '?')
							end_index = i + 2;
						else if (str[i + 1] == '{')
						{
							end_index = find_closing_bracket(str, i + 2);
							if (end_index == -1)
								return (ERR_VAR_SUBST);
						}
						else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
						{
							// Here I need to add new function to find end_index in the case of alnum / _ char
							// This code block bellow is wrong!
							++i;
							while (str[i])
							{
								if (ft_isalnum(str[i]) || str[i] == '_')
									++i;
								else
									break;
							}
						}
					}
				}
				++i;
			}
		}
		temp = temp->next;
	}
}

int	find_closing_bracket(char	*string, int start_index)
{
	while (string[start_index])
	{
		if (string[start_index] == '}')
			return (start_index);
		else if (ft_isalnum(string[start_index]) || string[start_index] == '_')
			++start_index;
		else
			return (-1);
	}
	return (-1);
}
