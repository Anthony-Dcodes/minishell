/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 10:50:57 by advorace          #+#    #+#             */
/*   Updated: 2026/06/01 12:23:13 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
	NO_QUOTE,
	END_QUOTE
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
