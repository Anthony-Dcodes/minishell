/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:42:08 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 11:08:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "macros.h"
#include "structs.h"



// String utils
size_t	ft_strlen(const char *s);
int	ft_isspace(char c);
int	ft_isalnum(int c);

// Syntax check
int check_syntax(t_token *head);
int has_unclosed_quote(char *str);

// Substitutions
int	substitute_vars(t_token *head);
int	find_closing_bracket(char	*string, int start_index);
int	get_variable_end_index(char	*string, int start_index);
int	replace_variable(t_token *token, char *evn_var, int start_index, int end_index);
int	get_variable_start_index(char *string, int start_index);
int get_substring_end_index(char *string, int start_index);

// Remove quotes
int	remove_quotes(t_token *head);
int	find_next_quote(char *str, int start, char quote_char);
int	remove_string_quotes(char *str, int first_quote, int second_quote, char **dest);
