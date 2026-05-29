/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_advorace.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:24:08 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 08:33:15 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "convert_to_tlistx.h"
#include "macros.h"
#include "parser.h"
#include "parser_advorace.h"
#include "remove_quotes.h"
#include "string_utils.h"
#include "substitution.h"
#include "syntax_checker.h"
#include "tokenizer.h"

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
