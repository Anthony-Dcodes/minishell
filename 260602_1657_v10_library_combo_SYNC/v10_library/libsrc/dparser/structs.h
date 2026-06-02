/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:08:09 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 21:31:14 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "macros.h"
#include <stddef.h>
#include "../../src/types/types.h"

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
