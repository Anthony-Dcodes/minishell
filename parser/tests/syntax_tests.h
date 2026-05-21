/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:20:16 by advorace          #+#    #+#             */
/*   Updated: 2026/05/21 12:05:04 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

typedef struct s_test
{
	char	*input;
	int		expected; // 0 = valid, 1 = syntax error
} t_test;

/*

1.
	| must have a complete command on both sides.

2.
	every redirection operator must be followed by exactly one word as its target.
	Anything else (another operator, a pipe, end of line) is a syntax error.

3.
	every opening quote needs a matching closing quote of the same type.
	In bash interactively this opens a continuation prompt; in minishell you report an unclosed-quote error.
*/

t_test tests[] = {
	// Valid
	{"echo hello", ERR_OK},
	{"echo hello | cat", ERR_OK},
	{"cat < file", ERR_OK},
	{"cat > file", ERR_OK},
	{"cat >> file", ERR_OK},
	{"cat << EOF", ERR_OK},
	{"echo 'hello'", ERR_OK},
	{"echo 'hello' 'world'", ERR_OK},
	// Invalid pipes
	{"| cat", ERR_SYNTAX},
	{"cat |", ERR_SYNTAX},
	{"cat | | cat", ERR_SYNTAX},
	// Invalid redirects
	{"cat >", ERR_SYNTAX},
	{"cat <", ERR_SYNTAX},
	{"cat > > file", ERR_SYNTAX},
	{"cat > | pipe", ERR_SYNTAX},
	// Closed quotes
	{"echo \"hello\"", ERR_OK},
	{"echo \"hel''l'o'\"", ERR_OK},
	{"'echo' \"hel''l'o'\"", ERR_OK},
	{"'echo' 'hello''world'", ERR_OK},
	{"echo \"hello\"'world'", ERR_OK},
	{"echo \"hello\"'wo\"r\"ld'", ERR_OK},
	{"echo \"hel'l'o'\"", ERR_OK},
	// unclosed quotes
	{"echo 'hello", ERR_SYNTAX},
	{"echo \"hello", ERR_SYNTAX},
	{"echo \" hello", ERR_SYNTAX},
	{"echo '\"hello", ERR_SYNTAX},
	{"echo \"he'llo", ERR_SYNTAX},
	{"echo \"hel''lo", ERR_SYNTAX},
	{"echo hello'rorld", ERR_SYNTAX},
	{"echo \"hello'\"'", ERR_SYNTAX},
	// Redirect at beginning (valid — your checker allows it)
	{"< file cat", ERR_OK},
	{"< file", ERR_OK},
	{"> file", ERR_OK},
	{"<< cat", ERR_OK},
	{">> cat", ERR_OK},

	// Chained pipes
	{"cat | grep foo | wc -l", ERR_OK},
	{"cat | grep | wc | head", ERR_OK},

	// Pipe next to redirect
	{"cat | > file", ERR_SYNTAX},     // pipe with redirect after, no word
	{"cat > file | grep", ERR_OK},    // redirect mid-pipeline, valid

	// Empty quotes (valid — empty string token)
	{"echo ''", ERR_OK},
	{"echo \"\"", ERR_OK},
	{"echo ''\"\"", ERR_OK},

	// Heredoc edge cases
	{"cat << EOF | grep foo", ERR_OK},
	{"cat <<", ERR_SYNTAX},
	{"ls >>", ERR_SYNTAX},
	{"ls >> 	 ", ERR_SYNTAX},
	{"ls >> 	 >", ERR_SYNTAX},
	{"ls >> 	 > cat | grep", ERR_SYNTAX},
	{"ls >> 	 > cat | >", ERR_SYNTAX},

	// Redirect followed by redirect
	{"cat >> >> file", ERR_SYNTAX},
	{"cat < < file", ERR_SYNTAX},

	// More pipe rules
	{"ls ||", ERR_SYNTAX},
	{"ls | |", ERR_SYNTAX},
	{"ls | | | |   | ", ERR_SYNTAX},
	{"|", ERR_SYNTAX},
	{" | ", ERR_SYNTAX},


	{NULL, 0}
};
