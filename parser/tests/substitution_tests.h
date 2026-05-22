/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_tests.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:00:00 by advorace          #+#    #+#             */
/*   Updated: 2026/05/22 13:27:04 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// Basic expansion
	{"$FOO",        "FOO",  "bar",      "bar",          ERR_OK},
	{"$FOO",        "FOO",  "hello",    "hello",        ERR_OK},
	{"$FOO",        "FOO",  "",         "",             ERR_OK},  // empty value

	// Unset variable → should expand to ""
	{"$UNSET_XYZ",  NULL,   NULL,       "",             ERR_OK},

	// Var in the middle of a word
	{"pre$FOO",     "FOO",  "bar",      "prebar",       ERR_OK},
	{"${FOO}suf",     "FOO",  "bar",      "${FOO}suf",       ERR_OK},  // careful: FOOsuf vs FOO
	{"pre${FOO}suf",  "FOO",  "bar",      "pre${FOO}suf",    ERR_OK},

	// Two vars in one token
	{"$A$B",        "A",    "hello",    "helloy",   ERR_OK},  // requires B=world too
	{"$A-$B",       "A",    "x",        "x-y",          ERR_OK},  // requires B=y

	// Double-quoted: should expand
	{"\"$FOO\"",    "FOO",  "bar",      "\"bar\"",      ERR_OK},

	// Single-quoted: should NOT expand — value passes through literally
	{"'$FOO'",      "FOO",  "bar",      "'$FOO'",       ERR_OK},

	// Double-quoted: should expand
	{"$C\"$FOO\"$B",    "FOO",  "bar",      "x\"bar\"y",      ERR_OK},

	// Single-quoted: should NOT expand — value passes through literally
	{"$C'$FOO'$B",      "FOO",  "bar",      "x'$FOO'y",       ERR_OK},

	// Double-quoted: should expand
	{"$C    \"$FOO\" $B",    "FOO",  "bar",      "x    \"bar\" y",      ERR_OK},

	// Single-quoted: should NOT expand — value passes through literally
	{"$C    '$FOO' $B",      "FOO",  "bar",      "x    '$FOO' y",       ERR_OK},

	// Multiple expansions
	{"$FOO$FOO",    "FOO",  "ab",       "abab",         ERR_OK},

	// Non expanding EVN names
	{"$", NULL, NULL, "$", ERR_OK},
	{"$ $", NULL, NULL, "$ $", ERR_OK},
	{"$0", NULL, NULL, "$0", ERR_OK},
	{"$1", NULL, NULL, "$1", ERR_OK},
	{"$6", NULL, NULL, "$6", ERR_OK},
	{"$$$", NULL, NULL, "$$$", ERR_OK},
	{"$$$@", NULL, NULL, "$$$@", ERR_OK},
	{"$$$.", NULL, NULL, "$$$.", ERR_OK},
	{"$1NAME.txt", "_NAME", "sam", "$1NAME.txt", ERR_OK},
	{"$-NAME.txt", "_NAME", "sam", "$-NAME.txt", ERR_OK},
	{"$.NAME.txt", "_NAME", "sam", "$.NAME.txt", ERR_OK},
	{"$*NAME.txt", "_NAME", "sam", "$*NAME.txt", ERR_OK},
	{"$\"NAME\".txt", "_NAME", "sam", "$\"NAME\".txt", ERR_OK},

	// Expanding ENV names
	{"$NAME/home", "NAME", "sam", "sam/home", ERR_OK},
	{"$NAME.txt", "NAME", "sam", "sam.txt", ERR_OK},
	{"$_NAME.txt", "_NAME", "sam", "sam.txt", ERR_OK},
	{"$NAME/home$NAME", "NAME", "sam", "sam/homesam", ERR_OK},
	{"$NAME/home/$NAME", "NAME", "sam", "sam/home/sam", ERR_OK},
	{"$NAME/home///$NAME", "NAME", "sam", "sam/home///sam", ERR_OK},
	{"$NAME/home$$NAME", "NAME", "sam", "sam/home$sam", ERR_OK},
	{"$NAME/home$5$NAME", "NAME", "sam", "sam/home$5sam", ERR_OK},
	{"$NAME/home$5$$$$NAME", "NAME", "sam", "sam/home$5$$$sam", ERR_OK},
	
	// Expanding not-set ENV
	{"$NAME/home", NULL, NULL, "/home", ERR_OK},
	{"$NAME$$/home", NULL, NULL, "$$/home", ERR_OK},
	{"$NAME$1/home", NULL, NULL, "$1/home", ERR_OK},
	{"$NAME$./home", NULL, NULL, "$./home", ERR_OK},
	{"$NAME$$$$./home", NULL, NULL, "$$$$./home", ERR_OK},
	{"$NAME$AGE./home", NULL, NULL, "./home", ERR_OK},
	{"$NAME$AGE$$./home", NULL, NULL, "$$./home", ERR_OK},
	{"$NAME$AGE$$#./home", NULL, NULL, "$$#./home", ERR_OK},

	// Non-expanding SINGLE quoted ENV NAMES
	{"'$NAME'.txt", "NAME", "sam", "'$NAME'.txt", ERR_OK},

	// Special cases
	{"echo$", NULL, NULL, "echo$", ERR_OK},
	{"$?", NULL, NULL, "(int)", ERR_OK},  // assumes last exit = ERR_OK

	// Sentinel
	{NULL, NULL, NULL, NULL, 0}
};
