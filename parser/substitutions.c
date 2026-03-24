/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:38:41 by advorace          #+#    #+#             */
/*   Updated: 2026/03/24 20:50:19 by advorace         ###   ########.fr       */
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
	char	*substring;
	char	*env_var;

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
						end_index = get_variable_end_index(str, i);
						if (end_index == -1)
							return (ERR_VAR_SUBST);
						if (get_string(i, end_index, str, &substring) == ERR_MALLOC)
							return (ERR_VAR_SUBST);
						env_var = getenv(substring);
						if (!env_var)
							return (ERR_VAR_SUBST);
						
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
			return (start_index + 1);
		else if (ft_isalnum(string[start_index]) || string[start_index] == '_')
			++start_index;
		else
			return (-1);
	}
	return (-1);
}

int	get_variable_end_index(char	*string, int start_index)
{
	int	i;

	i = start_index;
	if (string[i + 1] == '?')
		return (i + 2);
	else if (string[i + 1] == '{')
		return (find_closing_bracket(string, i + 2));
	else if (ft_isalnum(string[i + 1]) || string[i + 1] == '_')
	{
		++i;
		while (string[i])
		{
			if (ft_isalnum(string[i]) || string[i] == '_')
				++i;
			else
				break;
		}
		return (i);
	}
	return (-1);
}
