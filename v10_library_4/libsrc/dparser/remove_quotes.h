/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:06:42 by advorace          #+#    #+#             */
/*   Updated: 2026/06/01 15:22:21 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Remove quotes
int	remove_quotes(t_token *head);
int	find_next_quote(char *str, int start, char quote_char, t_token *head);
int	remove_string_quotes(int first_quote, int second_quote,
		char **dest, t_token *head);
int	find_and_remove_next_quote(t_token *temp, int *i);
int	alloc_dest_new_meta(t_token *head, char **dest, t_meta **new_meta);
