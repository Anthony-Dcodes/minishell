/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:06:58 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 11:09:03 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Linked list ops
t_token *new_token(char *value, int	type, int quote, int *ret);
void	append_token(t_token **head, t_token *token);
void	free_tokens(t_token **head);

// String helpers
int	find_start_index(char *str, int start);
int find_end_index(char *str, int start, int quote);
int	get_string(int start, int end, char *src, char **dst);
int	detect_quote(char c);
int	track_quote_state(int quote, char c);

// Tokenizer utils
int	get_string_type(char c);
int	tokenizer(t_token **head, char *src);
