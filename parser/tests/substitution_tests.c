/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:00:00 by advorace          #+#    #+#             */
/*   Updated: 2026/03/25 00:00:00 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substitution_tests.h"
#include <string.h>

// Builds a single WORD token directly — bypasses the lexer
// so we can test substitute_vars in isolation
static t_token	*make_word_token(char *value)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = WORD;
	tok->value = strdup(value);
	tok->next = NULL;
	return (tok);
}

int	main(void)
{
	int			i;
	int			passed;
	int			failed;
	t_token		*head;
	int			ret;

	i = 0;
	passed = 0;
	failed = 0;
    setenv("B", "world", 1);
    setenv("B", "y", 1);
	while (subst_tests[i].input != NULL)
	{
		// 1. Set up environment
		if (subst_tests[i].env_key)
			setenv(subst_tests[i].env_key, subst_tests[i].env_val, 1);

		// 2. Build a minimal token list
		head = make_word_token(subst_tests[i].input);
		if (!head)
		{
			printf("MALLOC ERR: %s\n", subst_tests[i].input);
			i++;
			continue ;
		}

		// 3. Run substitution
		ret = substitute_vars(head);

		// 4. Check error expectation
		if (subst_tests[i].expect_err && ret != ERR_OK)
		{
			printf("OK (err):  %-30s → got expected error\n",
				subst_tests[i].input);
			passed++;
		}
		else if (!subst_tests[i].expect_err && ret == ERR_OK
			&& strcmp(head->value, subst_tests[i].expected) == 0)
		{
			printf("OK:        %-30s → \"%s\"\n",
				subst_tests[i].input, head->value);
			passed++;
		}
		else
		{
			printf("FAIL:      %-30s → got \"%s\", expected \"%s\" (ret=%d)\n",
				subst_tests[i].input,
				head->value ? head->value : "(null)",
				subst_tests[i].expected,
				ret);
			failed++;
		}

		// 5. Tear down — unset so tests don't bleed into each other
		if (subst_tests[i].env_key)
			unsetenv(subst_tests[i].env_key);

		// free_token_list(head);
		i++;
	}
	printf("\n%d passed, %d failed\n", passed, failed);
	return (failed > 0);
}