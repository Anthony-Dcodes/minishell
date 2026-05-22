/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_tests.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:00:00 by advorace          #+#    #+#             */
/*   Updated: 2026/05/22 15:21:48 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../macros.h"
#include <stddef.h>

typedef struct s_quote_remove_test
{
	char	*input;        // raw token value (what the lexer would produce)
	char	*expected;     // expected token->value after substitute_vars
	int		expect_err;    // 0 = expect ERR_OK, 1 = expect ERR_VAR_SUBST
} t_quote_remove_test;

t_quote_remove_test quote_remove_test[] = {
	// Basic tests, no quotes left
	{"echo", "echo", 0},
	{"'echo'", "echo", 0},
	{"'''echo'''", "echo", 0},
	{"\"echo\"", "echo", 0},
	{"\"\"echo\"\"", "echo", 0},
	// Sentinel
	{NULL, NULL, 0}
};
