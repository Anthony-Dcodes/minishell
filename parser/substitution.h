/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:49:13 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 13:24:42 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Substitution valid env chars
int		envar_first_char_valid(char c);
int		envar_char_valid(char c);

// Substitution
char	*get_env_value(char *string);

// Substitutions
int		substitute_vars(t_token *head);
int		get_variable_end_index(char	*string, int start_index);
int		replace_variable(t_token *token, char *evn_var,
			int start_index, int end_index);
int		look_for_env_to_substitute(t_token *temp);
int		isolate_and_replace_env(t_token *temp, int *index);

// Substitutions copy job
int		init_copy_job(t_copy_job *copy_job, t_token *token, int len);
void	copy_upto_envar(t_copy_job *job, int end);
void	copy_envar_update_meta(t_copy_job *job, char *envar, int end);
void	copy_rest(t_copy_job *job, int end);
void	assign_to_token(t_token *token, t_copy_job *job);
