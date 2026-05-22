/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:49:13 by advorace          #+#    #+#             */
/*   Updated: 2026/05/22 13:55:01 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Substitution valid env chars
int	env_first_char_valid(char c);
int env_whitelist_char(char c);

// Substitution
char	*get_env_value(char *string);

// Substitutions
int	substitute_vars(t_token *head);
int	get_variable_end_index(char	*string, int start_index);
int	replace_variable(t_token *token, char *evn_var, int start_index, int end_index);
int	look_for_env_to_substitute(t_token *temp);
int isolate_and_replace_env(t_token *temp, int *index);
