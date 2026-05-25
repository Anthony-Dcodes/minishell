/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:08:09 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 10:25:20 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "macros.h"
#include <stddef.h>

typedef struct s_token
{
	char				*value;
	t_meta				*meta;
	size_t				len;
	t_quote				quote;
	t_type				type;
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
