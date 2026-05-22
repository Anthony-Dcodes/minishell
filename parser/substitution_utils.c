/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:48:53 by advorace          #+#    #+#             */
/*   Updated: 2026/05/22 13:14:14 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "macros.h"
#include "structs.h"
#include "substitution.h"
#include "utils.h"

char	*get_env_value(char *string)
{
	return (getenv(string));
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
