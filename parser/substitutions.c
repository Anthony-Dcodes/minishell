/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:38:41 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 08:46:47 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <stdlib.h>
#include "substitution.h"
#include "remove_quotes.h"
#include "string_utils.h"

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
			ret = look_for_env_to_substitute(temp);
			if (ret != ERR_OK)
				return (ret);
		}
		temp = temp->next;
	}
	return (ret);
}

int	look_for_env_to_substitute(t_token *temp)
{
	char	*str;
	int		i;
	int		quote;
	int		ret;

	str = temp->value;
	i = 0;
	quote = NO_QUOTE;
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
			if (envar_first_char_valid(str[i + 1]))
			{
				ret = isolate_and_replace_env(temp, &i);
				if (ret != ERR_OK)
					return (ret);
				str = temp->value;
				continue;
			}
		}
		++i;
	}
	return (ERR_OK);
}

int isolate_and_replace_env(t_token *temp, int *index)
{
	char	*str;
	int		end_index;
	int		start_index;
	char	*substring;
	char	*env_var;

	start_index = *index + 1;
	str = temp->value;
	end_index = get_variable_end_index(str, start_index + 1);
	if (get_string(start_index, end_index, str, &substring) == ERR_MALLOC)
		return (ERR_VAR_SUBST);
	env_var = get_env_value(substring);
	free(substring);
	if (replace_variable(temp, env_var, *index, end_index) != ERR_OK)
		return (ERR_VAR_SUBST);
	if (env_var != NULL)
		*index += ad_strlen(env_var);
	return (ERR_OK);
}
