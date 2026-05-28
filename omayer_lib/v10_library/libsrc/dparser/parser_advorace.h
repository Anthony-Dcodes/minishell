/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_advorace.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:24:08 by advorace          #+#    #+#             */
/*   Updated: 2026/05/28 21:39:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0

typedef enum e_error
{
	ERR_OK,
	ERR_MALLOC,
	ERR_SYNTAX,
	ERR_VAR_SUBST,
}	t_error;

typedef enum e_quote
{
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	NO_QUOTE
}	t_quote;

typedef enum e_type
{
	WORD,
	PIPE,
	REDDIRECT,
	END_FILE
}	t_type;

typedef enum e_meta
{
	UNQOUTED_CHAR,
	S_QUOTE,
	D_QOUTE,
	IN_S_QUOTE,
	IN_D_QUOTE,
	EXPANSION
}	t_meta;

typedef struct s_token
{
	char				*value;
	t_meta				*meta;
	size_t				len;
	t_quote				quote;
	t_type				type;
	struct s_token		*next;
	struct s_token		*previous;
}	t_token;

typedef struct s_copy_job
{
	int		i;
	int		j;
	char	*new_string;
	char	*old_string;
	t_meta	*new_meta;
	t_meta	*old_meta;
}	t_copy_job;

// typedef struct s_listex
// {
// 	char		**items;
// 	char		*xattr_qc;
// 	char		*xattr_pc;
// 	char		*xattr_sc;
// 	char		*xattr_pidx;
// 	char		*xattr_rc;
// 	size_t		size;
// }	t_listex;


int		get_n_pipes(t_token *head);
int		fill_tlistx(t_token *tokens, t_listex ***listex);
int		assign_quote(t_listex *listex, int quote);
int		allocate_t_listex_mem(t_listex ***listex, t_token *head);
int		assing_string(t_listex *listex, char *str, int i);
void	assign_size(t_listex *listex, int size);
int		get_n_tokens_before_next_pipe(t_token *head, int nth_pipe);
int		parser(char *input, t_listex ***listex);
int		remove_quotes(t_token *head);
int		find_next_quote(char *str, int start, char quote_char, t_token *head);
int		remove_string_quotes(char *str, int first_quote,
int		second_quote, char **dest, t_token *head);

		// String utils
size_t	ft_strlen(const char *s);
int		ft_isspace(char c);
int		ft_isalnum(int c);
int		get_string(int start, int end, char *src, char **dst);
void	*ft_memmove(void *dst, const void *src, size_t len);

//2
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);

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

int		syntax_checker(t_token *head);
int		has_unclosed_quote(char *str);

// Tokenizer token utils
t_token	*create_new_token(char *value, int type, int quote, int *ret);
void	append_token(t_token **head, t_token *token);
void	free_tokens(t_token **head);
t_token	*get_next_token(int start_index, char *src, int *ret, int *end_index);

// Token metadata
int		assign_word_token_meta_data(t_token *token);
void	print_token_metadata(t_token *token);
void	free_metadata(t_token *head);

// Tokenizer metadata utils
void	handle_no_quotes(t_token *token, int idx);
void	handle_single_quotes(t_token *token, int idx, char c);
void	handle_double_quotes(t_token *token, int idx, char c);

// Tokenizer char utils
int		detect_quote(char c);
int		track_quote_state(int quote, char c);
int		get_token_type(char c);
char	quote_to_char(int quote);

// Tokenizer string utils
int		find_start_index(char *str, int start);
int		find_end_index(char *str, int start, int quote);
int		get_string(int start, int end, char *src, char **dst);

// Tokenizer
int		tokenizer(t_token **head, char *src);
