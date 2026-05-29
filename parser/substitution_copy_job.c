/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_copy_job.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:48:23 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 08:46:47 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"
#include "string_utils.h"

int	init_copy_job(t_copy_job *copy_job, t_token *token, int len)
{
	copy_job->new_string = malloc(sizeof(char) * (len + 1));
	copy_job->new_meta = malloc(sizeof(t_meta) * len);
	if (!copy_job->new_string || !copy_job->new_meta)
		return (ERR_MALLOC);
	copy_job->i = 0;
	copy_job->j = 0;
	copy_job->old_string = token->value;
	copy_job->old_meta = token->meta;
	return (ERR_OK);
}

void	copy_upto_envar(t_copy_job *job, int end)
{
	int		i;

	i = job->i;
	while (i < end)
	{
		job->new_string[i] = job->old_string[i];
		job->new_meta[i] = job->old_meta[i];
		++i;
	}
	job->i = i;
}

void	copy_envar_update_meta(t_copy_job *job, char *envar, int end)
{
	int	i;
	int	j;

	i = job->i;
	j = job->j;
	while (j < end)
	{
		job->new_string[i + j] = envar[j];
		job->new_meta[i + j] = EXPANSION;
		++j;
	}
	job->j = j;
}

void	copy_rest(t_copy_job *job, int end)
{
	int	i;
	int	j;

	i = job->i;
	j = job->j;
	while (job->old_string[end])
	{
		job->new_string[i + j] = job->old_string[end];
		job->new_meta[i + j] = job->old_meta[end];
		++j;
		++end;
	}
	job->j = j;
}

void	assign_to_token(t_token *token, t_copy_job *job)
{
	free(token->value);
	token->value = job->new_string;
	token->len = ad_strlen(job->new_string);
	free(token->meta);
	token->meta = job->new_meta;
}
