/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:42:08 by advorace          #+#    #+#             */
/*   Updated: 2026/05/21 18:07:30 by advorace         ###   ########.fr       */
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
int syntax_checker(t_token *head);
int has_unclosed_quote(char *str);

// Remove quotes
int	remove_quotes(t_token *head);
int	find_next_quote(char *str, int start, char quote_char);
int	remove_string_quotes(char *str, int first_quote, int second_quote, char **dest);
