/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:38:41 by advorace          #+#    #+#             */
/*   Updated: 2026/05/21 18:13:31 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "tokenizer.h"
#include <stdlib.h>
#include "substitution.h"

int	substitute_vars(t_token *head)
{
	t_token *temp;
	char	*str;
	int		i;
	int		quote;
	int		end_index;
	int		start_index;
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
						// special case need to replace $? with last exit code
						if (str[i + 1] == '?')
						{
							++i;
							continue;
						}
						if (!env_first_char_valid(str[i + 1]))
						{
							i += 1;
							continue;
						}
						start_index = i + 1;
						end_index = get_variable_end_index(str, start_index + 1);
						if (get_string(start_index, end_index, str, &substring) == ERR_MALLOC)
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
