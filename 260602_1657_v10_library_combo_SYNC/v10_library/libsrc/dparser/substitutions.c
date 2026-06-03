/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitutions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:38:41 by advorace          #+#    #+#             */
/*   Updated: 2026/06/02 17:17:22 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <stdlib.h>
#include "substitution.h"
#include "remove_quotes.h"
#include "string_utils.h"
#include "stdio.h"
#include "../../src/shell/sh/sh_env2.h"

int	substitute_vars(t_s *s, t_token *head, char **envp)
{
	t_token	*temp;
	int		ret;

	temp = head;
	ret = ERR_OK;
	while (temp)
	{
		if (temp->type == WORD)
		{
			ret = look_for_env_to_substitute(s, temp, envp);
			if (ret != ERR_OK)
				return (ret);
		}
		temp = temp->next;
	}
	return (ret);
}

int	look_for_env_to_substitute(t_s *s, t_token *temp, char **envp)
{
	char	*str;
	int		i;
	int		quote;

	str = temp->value;
	i = 0;
	quote = NO_QUOTE;
	while (str[i])
	{
		quote = track_quote_state(quote, str[i]);
		if ((quote == NO_QUOTE || quote == DOUBLE_QUOTE)
			&& str[i] == '$')
		{
			if (envar_first_char_valid(str[i + 1]))
			{
				if (isolate_and_replace_env(s, temp, &i, envp) != ERR_OK)
					return (ERR_VAR_SUBST);
				str = temp->value;
				continue ;
			}
		}
		++i;
	}
	return (ERR_OK);
}

int	isolate_and_replace_env(t_s *s, t_token *temp, int *index, char **envp)
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
	if (ft_equal2(s, substring, "?", TRUE))
		ft_getenv2d(s, envp, L_SHLES, &env_var);
	else
		ft_wgetenv2d(s, envp, substring, &env_var);
	free(substring);
	if (replace_variable(temp, env_var, *index, end_index) != ERR_OK)
		return (ERR_VAR_SUBST);
	if (env_var != NULL)
		*index += ad_strlen(env_var);
	return (ERR_OK);
}
