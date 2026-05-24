/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:06:58 by advorace          #+#    #+#             */
/*   Updated: 2026/05/24 12:22:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Tokenizer token utils
t_token *create_new_token(char *value, int	type, int quote, int *ret);
void	append_token(t_token **head, t_token *token);
void	free_tokens(t_token **head);
t_token	*get_next_token(int start_index, char *src, int *ret, int *end_index);

// Token metadata
int	assign_word_token_meta_data(t_token *token);
void print_token_metadata(t_token *token);
void free_metadata(t_token *head);

// Tokenizer char utils
int	detect_quote(char c);
int	track_quote_state(int quote, char c);
int	get_token_type(char c);

// Tokenizer string utils
int	find_start_index(char *str, int start);
int find_end_index(char *str, int start, int quote);
int	get_string(int start, int end, char *src, char **dst);

// Tokenizer
int	tokenizer(t_token **head, char *src);
