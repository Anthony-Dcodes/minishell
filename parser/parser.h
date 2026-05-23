/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:42:08 by advorace          #+#    #+#             */
/*   Updated: 2026/05/23 17:01:46 by advorace         ###   ########.fr       */
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
