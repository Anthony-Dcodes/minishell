/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:42:08 by advorace          #+#    #+#             */
/*   Updated: 2026/03/24 21:44:32 by advorace         ###   ########.fr       */
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
} t_error;

typedef enum e_quote
{
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	NO_QUOTE
} t_quote;

typedef enum e_type
{
	WORD,
	PIPE,
	REDDIRECT,
	END_FILE
} t_type;

typedef struct s_token
{
	char		*value;
	t_quote		quote;
	t_type		type;
	struct s_token		*next;
	struct s_token		*previous;
} t_token;

typedef struct s_listex
{
	char		**items;
	char		*xattr_qc;
	char		*xattr_pc;
	char		*xattr_sc;
	char		*xattr_pidx;
	char		*xattr_rc;
	size_t		size;
}	t_listex;

//int ft_parsecmd(t_s *s, char *src, t_listex **dst, char **envp);

// Linked list ops
t_token *new_token(char *value, int	type, int quote, int *ret);
void	append_token(t_token **head, t_token *token);

// String helpers
int	find_start_index(char *str, int start);
int find_end_index(char *str, int start, int quote);
int	get_string(int start, int end, char *src, char **dst);
int	detect_quote(char c);
int	track_quote_state(int quote, char c);

// Tokenizer utils
int	get_string_type(char c);
int	tokenizer(t_token **head, char *src);

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
