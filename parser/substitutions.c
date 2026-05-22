/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:38:41 by advorace          #+#    #+#             */
/*   Updated: 2026/05/22 12:52:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "tokenizer.h"
#include <stdlib.h>
#include "substitution.h"

int	substitute_vars(t_token *head)
{
	t_token *temp;
	int		ret;

	temp = head;
	ret = ERR_OK;
	while (temp)
	{
		if (temp->type == WORD)
		{
			ret = check_for_env_to_substitute(temp);
			if (ret != ERR_OK)
				return (ret);
		}
		temp = temp->next;
	}
	return (ret);
}

int	get_variable_end_index(char	*string, int start_index)
{
	int	i;

	i = start_index;
	while (string[i])
	{
		if (env_whitelist_char(string[i]))
			++i;
		else
			break;
	}
	return (i);
}

int	replace_variable(t_token *token, char *evn_var,
	int start_index, int end_index)
{
	char	*new_string;
	char	*old_string;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	old_string = token->value;
	len = (int)ft_strlen(old_string) - (end_index - start_index)
		+ (int)ft_strlen(evn_var);
	new_string = malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (ERR_MALLOC);
	while (i < start_index)
		new_string[i++] = old_string[i];
	while (j < (int)ft_strlen(evn_var))
		new_string[i + j++] = evn_var[j];
	while (old_string[end_index])
		new_string[i + j++] = old_string[end_index++];
	new_string[i + j] = 0;
	free(old_string);
	token->value = new_string;
	return (ERR_OK);
}

int	check_for_env_to_substitute(t_token *temp)
{
	char	*str;
	int		i;
	int		quote;
	int		ret;

	str = temp->value;
	i = 0;
	while(str[i])
	{
		quote = track_quote_state(quote, str[i]);
		if ((quote == NO_QUOTE || quote == DOUBLE_QUOTE)
			&& str[i] == '$')
		{
			// special case need to replace $? with last exit code
			if (str[i + 1] == '?')
			{
				++i;
				continue;
			}
			if (env_first_char_valid(str[i + 1]))
			{
				ret = isolate_and_replace_env(temp, i);
				if (ret != ERR_OK)
					return (ret);
				str = temp->value;
				i = -1; // start from beggining of the string
			}
		}
		++i;
	}
	return (ERR_OK);
}

int isolate_and_replace_env(t_token *temp, int index)
{
	char	*str;
	int		end_index;
	int		start_index;
	char	*substring;
	char	*env_var;
	
	start_index = index + 1;
	str = temp->value;
	end_index = get_variable_end_index(str, start_index + 1);
	if (get_string(start_index, end_index, str, &substring) == ERR_MALLOC)
		return (ERR_VAR_SUBST);
	env_var = get_env_value(substring);
	free(substring);
	if (replace_variable(temp, env_var, index, end_index) != ERR_OK)
		return (ERR_VAR_SUBST);
	return (ERR_OK);
}
