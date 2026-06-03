/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:06:58 by advorace          #+#    #+#             */
/*   Updated: 2026/06/03 12:38:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Tokenizer token utils
t_token	*create_new_token(char *value, int type, int quote, int *ret);
void	append_token(t_token **head, t_token *token);
void	free_tokens(t_token **head);
t_token	*get_next_token(int start_index, char *src, int *ret, int *end_index);
int		free_token(t_token *token, int ret);

// Token metadata
int		assign_word_token_meta_data(t_token *token);
void	print_token_metadata(t_token *token);
void	free_metadata(t_token *head);

// Tokenizer metadata utils
void	handle_no_quotes(t_token *token, int idx, char c);
void	handle_single_quotes(t_token *token, int idx, char c);
void	handle_double_quotes(t_token *token, int idx, char c);

// Tokenizer char utils
int		detect_quote(char c);
int		track_quote_state(int quote, char c);
int		get_token_type(char c);
char	quote_to_char(int quote);
int		track_quote_state_v2(int quote, char c);

// Tokenizer string utils
int		find_start_index(char *str, int start);
int		find_end_index(char *str, int start, int quote);
int		get_string(int start, int end, char *src, char **dst);

// Tokenizer
int		tokenizer(t_token **head, char *src);

// Tokenizer add spaces
int		add_spaces(t_token **head);
int		create_extra_spaced_str(char **str, t_token *token);
void	assing_tokens_and_free(t_token **bef, t_token **aft, t_token **temp);
void	reassing_tokens_and_advance(t_token **bef,
			t_token **aft, t_token **temp);
int		not_valid_add_spaces_token(t_token *token);
int		relink_tokens(t_token **bef, t_token **aft, t_token **temp, int ret);
