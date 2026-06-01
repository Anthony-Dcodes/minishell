/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:20:16 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 10:33:51 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../macros.h"

typedef struct s_test
{
	char	*input;
	int		expected; // 0 = valid, 1 = syntax error
} t_test;

/*

1.
	Pipes must have a complete command on both sides.

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
	{"cat | > file", ERR_OK},     // pipe with redirect after, no word
	{"cat > file | grep", ERR_OK},    // redirect mid-pipeline, valid
	{"echo hi | > out", ERR_OK},
	{"echo hi | >> out", ERR_OK},
	{"cat | < in wc -1", ERR_OK},
	{"cat | << EOF", ERR_OK},

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

	// Balanced quote arrangements — must all parse as valid
	{"'echo'", ERR_OK},
	{"'''echo'''", ERR_OK},
	{"\"\"echo\"\"", ERR_OK},
	{"\"\"\"\"echo\"\"\"\"", ERR_OK},
	{"\"echo\"a\"echo\"", ERR_OK},
	{"'echo''a''echo'", ERR_OK},
	{"\"'echo'\"", ERR_OK},          // opposite-type inside must not break the counter
	{"'\"echo\"'", ERR_OK},
	{"\"ec'ho\"", ERR_OK},
	{"'ec\"ho'", ERR_OK},
	{"\"hel''l'o'\"", ERR_OK},

	// --- Operators are LITERAL inside quotes: the checker must NOT fire here ---
	{"echo \"|\"", ERR_OK},
	{"echo '|'", ERR_OK},
	{"echo \"a|b\"", ERR_OK},          // naive scanner splits on | -> false unclosed-quote error
	{"echo \"a > b\"", ERR_OK},
	{"echo \">\"", ERR_OK},
	{"echo \"<<\"", ERR_OK},
	{"\"echo|cat\"", ERR_OK},          // pipe literal -> ONE command
	{"\"echo\"|\"cat\"", ERR_OK},      // real pipe between two quoted commands
	// --- VALID multi-redirect (you only ever test the invalid redir->redir case) ---
	{"cat < in > out", ERR_OK},
	{"cat > a > b", ERR_OK},
	{"< in < in2 cat", ERR_OK},
	{"> a > b", ERR_OK},
	{"cat > out hello", ERR_OK},       // word after a satisfied redirect
	{"> a b", ERR_OK},                 // target a, command b
	// --- Quoted words as redirect targets ---
	{"cat > \"file\"", ERR_OK},
	{"cat > 'out file'", ERR_OK},
	{"cat < \"in\" | grep x", ERR_OK},
	// --- Redirect AFTER a pipe, with a valid target ---
	{"cat | grep x > out", ERR_OK},
	{"echo hi | cat > file", ERR_OK},
	// --- Bare operators: neither command nor target ---
	{">", ERR_SYNTAX},
	{"<", ERR_SYNTAX},
	{">>", ERR_SYNTAX},
	{"<<", ERR_SYNTAX},
	// --- Empty / whitespace-only input is a no-op, NOT a syntax error ---
	{"", ERR_OK},
	{"   ", ERR_OK},
	{"\t", ERR_OK},
	{"  echo hello  ", ERR_OK},        // surrounding whitespace trimmed

	{NULL, 0}
};
