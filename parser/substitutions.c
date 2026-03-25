/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:38:41 by advorace          #+#    #+#             */
/*   Updated: 2026/03/25 23:21:08 by advorace         ###   ########.fr       */
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
	int		start_index;
	int		end_of_sub_str;
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
						start_index = get_variable_start_index(str, i);
						end_of_sub_str = get_substring_end_index(str, i);
						//printf("start inde: %d, end index: %d\n", start_index, end_index);
						if (end_index == -1 || start_index == -1)
							return (ERR_VAR_SUBST);
						if (get_string(start_index, end_of_sub_str, str, &substring) == ERR_MALLOC)
							return (ERR_VAR_SUBST);
						//printf("string to getenv: %s\n", substring);
						env_var = getenv(substring);
						free(substring);
						if (replace_variable(temp, env_var, i, end_index) != ERR_OK)
							return (ERR_VAR_SUBST);
						str = temp->value;
						i = -1;
					}
				}
				++i;
			}
		}
		temp = temp->next;
	}
	return (ERR_OK);
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

int get_substring_end_index(char *string, int start_index)
{
	int	i;

	i = start_index;
	if (string[i + 1] == '?')
		return (i + 2);
	else if (string[i + 1] == '{')
		return (find_closing_bracket(string, i + 2) - 1);
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

int	get_variable_start_index(char *string, int start_index)
{
	int	i;

	i = start_index;
	if (string[i + 1] == '?')
		return (i + 1);
	else if (string[i + 1] == '{')
		return (i + 2);
	else if (ft_isalnum(string[i + 1]) || string[i + 1] == '_')
		return (i + 1);
	return (-1);

}

int	replace_variable(t_token *token, char *evn_var, int start_index, int end_index)
{
	char	*new_string;
	char	*old_string;
	int		i;
	int		j;
	int		len;

	old_string = token->value;
	len =(int)ft_strlen(old_string) - (end_index - start_index) + (int)ft_strlen(evn_var);
	new_string = malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (ERR_MALLOC);
	j = 0;
	i = 0;
	while (i < start_index)
	{
		new_string[i] = old_string[i];
		++i;
	}
	while (j < (int)ft_strlen(evn_var))
	{
		new_string[i + j] = evn_var[j];
		++j;
	}
	while (old_string[end_index])
	{
		new_string[i + j] = old_string[end_index];
		++end_index;
		++j;
	}
	new_string[i + j] = 0;
	free(old_string);
	token->value = new_string;
	return (ERR_OK);
}
