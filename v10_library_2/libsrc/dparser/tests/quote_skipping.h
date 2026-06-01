/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_skipping.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:26:44 by advorace          #+#    #+#             */
/*   Updated: 2026/05/24 16:09:37 by advorace         ###   ########.fr       */
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

	{"\"$NAME\"", "NAME", "sam", "sam", ERR_OK},
	{"'$NAME'", "NAME", "sam", "$NAME", ERR_OK},
	{"\"$NAME\"''", "NAME", "sam", "sam", ERR_OK},
	{"''\"$NAME\"", "NAME", "sam", "sam", ERR_OK},
	{"'\"$NAME\"'", "NAME", "sam", "\"$NAME\"", ERR_OK},

	{"hello$NAME/good?", "NAME", "sam", "hellosam/good?", ERR_OK},
	{"'hello'$NAME/good?", "NAME", "sam", "hellosam/good?", ERR_OK},
	{"'hello'$NAME/'good?'", "NAME", "sam", "hellosam/good?", ERR_OK},
	{"'h''''ello'$NAME/'good?'", "NAME", "sam", "hellosam/good?", ERR_OK},
	{"'h''''e'l'l'o''$NAME/'good?'", "NAME", "sam", "hellosam/good?", ERR_OK},
	{"'h''''e'l'l'o''$NAME/'g''''''o'o'd?'", "NAME", "sam", "hellosam/good?", ERR_OK},
	{"'h''''e'l'l'o''''$NAME''/'''g''''''o'o'd?'", "NAME", "sam", "hellosam/good?", ERR_OK},



	{"hello$NAME/good?", "NAME", "'sam'", "hello'sam'/good?", ERR_OK},
	{"'hello'$NAME/good?", "NAME", "'sam'", "hello'sam'/good?", ERR_OK},
	{"'hello'$NAME/'good?'", "NAME", "'sam'", "hello'sam'/good?", ERR_OK},
	{"'h'e'l'l'o'$NAME/'good?'", "NAME", "'sam'", "hello'sam'/good?", ERR_OK},
	{"'h'e'l'l'o'$NAME/'g'o'o'd'?'", "NAME", "'sam'", "hello'sam'/good?", ERR_OK},
	{"'h'e'l'l'o'''''$NAME''''/'g'o'o'd'?'", "NAME", "'sam'", "hello'sam'/good?", ERR_OK},
	{"'h'e'l'l'o'''''$NAME'''''/''g'o'o'd'?'", "NAME", "'sam'", "hello'sam'/good?", ERR_OK},




	{"hello$NAME/good?", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},
	{"hello$NAME/good?", "NAME", "'''sam'''", "hello'''sam'''/good?", ERR_OK},
	{"hello$NAME/good?", "NAME", "'''sam", "hello'''sam/good?", ERR_OK},
	{"hello$NAME/good?", "NAME", "sam'''", "hellosam'''/good?", ERR_OK},

	{"hello$NAME/good?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"'hello'$NAME/good?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"'hello'$NAME/'good'?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"'h'e'l'l'o'$NAME/'good'?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"'h'e'l'l'o'$NAME/'g'o'o'd''?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"'h'e'l'l'o'$NAME''/'g'o'o'd''?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"'h'e'l'l'o'''''$NAME''/'g'o'o'd''?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},


	{"hello$NAME/good?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"\"hello\"$NAME/good?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"\"hello\"$NAME/\"good?\"", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"\"hello\"$NAME\"/\"\"good?\"", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"\"h\"e\"l\"l\"o\"$NAME\"/\"\"good?\"", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},
	{"\"h\"e\"l\"l\"o\"$NAME\"/\"\"g\"o\"o\"d\"?\"", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},


	{"\"h'e'l'l'o\"$NAME/good?", "NAME", "''sam''", "h'e'l'l'o''sam''/good?", ERR_OK},
	{"\"h'e'l'l'o\"$NAME/\"good\"?", "NAME", "''sam''", "h'e'l'l'o''sam''/good?", ERR_OK},
	{"\"h'e'l'l'o\"$NAME/\"good\"'?'", "NAME", "''sam''", "h'e'l'l'o''sam''/good?", ERR_OK},
	{"\"h'e'l'l'o\"$NAME/\"g'o'o'd\"'?'", "NAME", "''sam''", "h'e'l'l'o''sam''/g'o'o'd?", ERR_OK},


	{"hello$NAME/good?", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},
	{"hello$NAME/good?", "NAME", "'''sam''", "hello'''sam''/good?", ERR_OK},
	{"hello$NAME/good?", "NAME", "'''''sam''", "hello'''''sam''/good?", ERR_OK},


	{"'h'e'l'l'o'$NAME/good?", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},
	{"'h'e'l'l'o'$NAME/'g'o'o'd'?'", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},
	{"'h'e'l'l'o'$NAME''/'g'o'o'd'?'", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},
	{"'h'e'l'l'o'''$NAME''/'g'o'o'd'?'", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},
	{"'h'e'l'l'o'''\"$NAME\"''/'g'o'o'd'?'", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},
	{"'h'e'l'l'o'''\"$NAME\"''/'g'o'o'd'?'", "NAME", "''sam''", "hello''sam''/good?", ERR_OK},



	{"hello$NAME/good?", "NAME", "\"\"sam\"\"", "hello\"\"sam\"\"/good?", ERR_OK},
	{"hello$NAME/good?", "NAME", "\"\"\"sam\"\"\"", "hello\"\"\"sam\"\"\"/good?", ERR_OK},
	{"hello$NAME/good?", "NAME", "\"\"sam", "hello\"\"sam/good?", ERR_OK},


	{"'hello'$NAME/good?", "NAME", "\"sam\"", "hello\"sam\"/good?", ERR_OK},



	{"echo 'hello_world'$NAME", "NAME", "sam", "echo hello_worldsam", ERR_OK},
	{"echo 'hello_world'$NAME", "NAME", "\"sam\"", "echo hello_world\"sam\"", ERR_OK},

	{"echo 'hello_world'$NAME", "NAME", "'sam'", "echo hello_world'sam'", ERR_OK},

	{"echo 'hello_world'$NAME/joke", "NAME", "'sam'", "echo hello_world'sam'/joke", ERR_OK},
	{"echo 'hello_world'$NAME'man'", "NAME", "'sam'", "echo hello_world'sam'man", ERR_OK},
	{"echo 'hello_world'$NAME'man'", "NAME", "\"sam\"", "echo hello_world\"sam\"man", ERR_OK},
	{"echo 'hello_world'$NAME", "NAME", "\"sam\"", "echo hello_world\"sam\"", ERR_OK},
	{"echo 'hello_world'$NAME\"man\"", "NAME", "'sam'", "echo hello_world'sam'man", ERR_OK},
	{"echo 'hello_world'$NAME\"man\"", "NAME", "\"sam\"", "echo hello_world\"sam\"man", ERR_OK},
	{"echo \"hello my name is $NAME\"", "NAME", "\"sam\"", "echo hello my name is \"sam\"", ERR_OK},
	{"echo \"hello my name is $NAME\"", "NAME", "'sam'", "echo hello my name is 'sam'", ERR_OK},
	{"a_$NAME/a", "NAME", "sam", "a_sam/a", ERR_OK},
	{"hello_$NAME/how_are_you?", "NAME", "'sam'", "hello_'sam'/how_are_you?", ERR_OK},
	{"'hello_'$NAME'_how_''are_''you?'", "NAME", "'sam'", "hello_'sam'_how_are_you?", ERR_OK},

	// Sentinel
	{NULL, NULL, NULL, NULL, 0}
};
