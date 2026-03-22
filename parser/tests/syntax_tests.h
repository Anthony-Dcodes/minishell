/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:20:16 by advorace          #+#    #+#             */
/*   Updated: 2026/03/22 18:33:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

typedef struct s_test
{
	char	*input;
	int		expected; // 0 = valid, 1 = syntax error
} t_test;

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
	// unclosed quotes
	{"echo 'hello", ERR_SYNTAX},
	{"echo \"hello", ERR_SYNTAX},
	{NULL, 0}
};
