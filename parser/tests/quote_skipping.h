/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_skipping.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:26:44 by advorace          #+#    #+#             */
/*   Updated: 2026/05/23 16:41:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../macros.h"

typedef struct s_subst_test
{
	char	*input;        // raw token value (what the lexer would produce)
	char	*env_key;      // env var to set before test (NULL = skip setenv)
	char	*env_val;      // value to give it
	char	*expected;     // expected token->value after substitute_vars
	int		expect_err;    // 0 = expect ERR_OK, 1 = expect ERR_VAR_SUBST
} t_subst_test;

t_subst_test subst_tests[] = {

	{"echo 'hello_world'$NAME", "NAME", "'sam'", "echo hello_world'sam'", ERR_OK},
	{"echo 'hello_world'$NAME'man'", "NAME", "'sam'", "echo hello_world'sam'man", ERR_OK},
	{"echo 'hello_world'$NAME", "NAME", "\"sam\"", "echo hello_world\"sam\"", ERR_OK},
	{"echo \"hello my name is $NAME\"", "NAME", "\"sam\"", "echo hello my name is \"sam\"", ERR_OK},
	{"echo \"hello my name is $NAME\"", "NAME", "'sam'", "echo hello my name is 'sam'", ERR_OK},

	// Sentinel
	{NULL, NULL, NULL, NULL, 0}
};
