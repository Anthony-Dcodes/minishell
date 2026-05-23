/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_tests.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:00:00 by advorace          #+#    #+#             */
/*   Updated: 2026/05/23 14:47:28 by advorace         ###   ########.fr       */
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
	{"\"\"echo", "echo", 0},
	{"echo\"\"", "echo", 0},
	{"''echo", "echo", 0},
	{"echo''", "echo", 0},
	{"\"\"\"\"echo\"\"\"\"", "echo", 0},
	{"''''echo''''", "echo", 0},

	// No quotes left same quote
	{"\"echo\"a\"echo\"", "echoaecho", 0},
	{"\"echoaecho\"", "echoaecho", 0},
	{"'echo'a'echo'", "echoaecho", 0},
	{"\"echo\"\"a\"\"echo\"", "echoaecho", 0},
	{"'echo''a''echo'", "echoaecho", 0},

	// Some quotes left
	{"\"'echo'\"", "'echo'", 0},
	{"'\"echo\"'", "\"echo\"", 0},
	{"\"'ec'ho'\"", "'ec'ho'", 0},
	{"'\"ec\"ho\"'", "\"ec\"ho\"", 0},

	// Quote in the middle left
	{"\"ec'ho\"", "ec'ho", 0},
	{"'ec\"ho'", "ec\"ho", 0},

	// Empty string results (must still produce an EMPTY token, not NULL)
	{"\"\"", "", 0},
	{"''", "", 0},
	{"\"\"''", "", 0},
	{"''\"\"", "", 0},
	{"\"\"\"\"", "", 0},
	{"''''", "", 0},
	{"a\"\"b", "ab", 0},          // empty quote mid-word vanishes, concatenates
	{"a''b", "ab", 0},

	// Whitespace preserved inside quotes (the whole reason quotes exist)
	{"\"a b\"", "a b", 0},
	{"'a b'", "a b", 0},
	{"\"  \"", "  ", 0},
	{"a\" \"b", "a b", 0},
	{"\"a b\"c", "a bc", 0},
	{"'hello world'", "hello world", 0},

	// Mixed quote types concatenating into one word
	{"\"a\"'b'", "ab", 0},
	{"'a'\"b\"", "ab", 0},
	{"\"a\"'b'\"c\"", "abc", 0},
	{"'a'\"b\"'c'", "abc", 0},
	{"x\"a\"'b'y", "xaby", 0},

	// Shell metacharacters are literal inside quotes (lexer must not have split these)
	{"\"a|b\"", "a|b", 0},
	{"'a;b'", "a;b", 0},
	{"\"a>b<c\"", "a>b<c", 0},
	{"'*'", "*", 0},
	{"\"a&&b\"", "a&&b", 0},
	
	// Minimal opposite-type quote preserved
	{"\"'\"", "'", 0},
	{"'\"'", "\"", 0},
	{"\"a'b'c\"", "a'b'c", 0},    // a pair of single quotes literal inside double
	{"'a\"b\"c'", "a\"b\"c", 0},

	// Sentinel
	{NULL, NULL, 0}
};
