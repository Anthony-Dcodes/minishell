/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:48:53 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 08:46:47 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "macros.h"
#include "structs.h"
#include "substitution.h"
#include "string_utils.h"

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
		if (envar_char_valid(string[i]))
			++i;
		else
			break ;
	}
	return (i);
}

int	replace_variable(t_token *token, char *evn_var,
	int start_index, int end_index)
{
	t_copy_job	copy_job;
	int			len;
	int			ret;

	len = (int)ad_strlen(token->value) - (end_index - start_index)
		+ (int)ad_strlen(evn_var);
	ret = init_copy_job(&copy_job, token, len);
	if (ret != ERR_OK)
		return (ret);
	copy_upto_envar(&copy_job, start_index);
	copy_envar_update_meta(&copy_job, evn_var, (int)ad_strlen(evn_var));
	copy_rest(&copy_job, end_index);
	copy_job.new_string[copy_job.i + copy_job.j] = 0;
	assign_to_token(token, &copy_job);
	return (ERR_OK);
}
