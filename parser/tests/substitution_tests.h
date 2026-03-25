/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_tests.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:00:00 by advorace          #+#    #+#             */
/*   Updated: 2026/03/25 23:24:05 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

typedef struct s_subst_test
{
	char	*input;        // raw token value (what the lexer would produce)
	char	*env_key;      // env var to set before test (NULL = skip setenv)
	char	*env_val;      // value to give it
	char	*expected;     // expected token->value after substitute_vars
	int		expect_err;    // 0 = expect ERR_OK, 1 = expect ERR_VAR_SUBST
} t_subst_test;

t_subst_test subst_tests[] = {
	// Basic expansion
	{"$FOO",        "FOO",  "bar",      "bar",          0},
	{"$FOO",        "FOO",  "hello",    "hello",        0},
	{"$FOO",        "FOO",  "",         "",             0},  // empty value

	// Unset variable → should expand to ""
	{"$UNSET_XYZ",  NULL,   NULL,       "",             0},

	// Var in the middle of a word
	{"pre$FOO",     "FOO",  "bar",      "prebar",       0},
	{"${FOO}suf",     "FOO",  "bar",      "barsuf",       0},  // careful: FOOsuf vs FOO
	{"pre${FOO}suf",  "FOO",  "bar",      "prebarsuf",    0},

	// Two vars in one token
	{"$A$B",        "A",    "hello",    "helloy",   0},  // requires B=world too
	{"$A-$B",       "A",    "x",        "x-y",          0},  // requires B=y

	// Double-quoted: should expand
	{"\"$FOO\"",    "FOO",  "bar",      "\"bar\"",      0},

	// Single-quoted: should NOT expand — value passes through literally
	{"'$FOO'",      "FOO",  "bar",      "'$FOO'",       0},

	// $ at end of string — no var name, literal $
	{"echo$",       NULL,   NULL,       "echo$",        0},

	// $? expansion (special case — needs last exit code)
	{"$?",          NULL,   NULL,       "0",            0},  // assumes last exit = 0

	// Multiple expansions
	{"$FOO$FOO",    "FOO",  "ab",       "abab",         0},

	// Sentinel
	{NULL, NULL, NULL, NULL, 0}
};
