/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:49:13 by advorace          #+#    #+#             */
/*   Updated: 2026/05/21 18:13:05 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

int	env_first_char_valid(char c);
int env_whitelist_char(char c);

// Substitutions
int	substitute_vars(t_token *head);
int	get_variable_end_index(char	*string, int start_index);
int	replace_variable(t_token *token, char *evn_var, int start_index, int end_index);
