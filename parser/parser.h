/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:42:08 by advorace          #+#    #+#             */
/*   Updated: 2026/03/17 21:54:53 by advorace         ###   ########.fr       */
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
} t_error;

typedef enum e_quote
{
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	NO_QUOTE
} t_quote;

typedef struct s_tokens
{
	char		*value;
	int			is_pipe;
	t_quote		quote;
	t_token		*next;
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
t_token *new_token(char *value, int	is_pipe, int quote, int *ret);
void	append_token(t_token **head, t_token *new);

// String helpers
int	find_start_index(char *str, int start);
int find_end_index(char *str, int start, int quote);
int	get_string(int start, int end, char *src, char **dst);
int	detect_quote(char c);
int	detect_pipe(char c);

// lexer
int	lexer(t_token **head, char *src);
