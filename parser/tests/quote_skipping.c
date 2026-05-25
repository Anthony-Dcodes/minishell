/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_skipping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:43:06 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 11:15:12 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "quote_skipping.h"
#include <string.h>
#include "../macros.h"
#include "macros.h"
#include "../structs.h"
#include "../substitution.h"
#include "../tokenizer.h"
#include "../remove_quotes.h"
#include "../string_utils.h"

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
	tok->len = ft_strlen(value);
	assign_word_token_meta_data(tok);
	return (tok);
}


int	main(void)
{
	int			i;
	int			passed;
	int			failed;
	int			wrong_error_code;
	t_token		*head;
	int			ret;

	i = 0;
	passed = 0;
	failed = 0;
	wrong_error_code = 0;
    setenv("B", "world", 1);
    setenv("B", "y", 1);
	setenv("C", "x", 1);
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
		ret = remove_quotes(head);

		if (strcmp(head->value, subst_tests[i].expected) == 0)
		{
			if (subst_tests[i].expect_err == ret)
			{
				printf("OK:        %-30s → %s\n",
					subst_tests[i].input, head->value);
				passed++;
			}
			else
			{
				printf("OK:        %-30s → %s, wrong error code, got %d, expected %d\n",
				subst_tests[i].input, head->value,
				ret,
				subst_tests[i].expect_err);
				passed++;
				wrong_error_code++;
			}
		}
		else
		{
			printf("FAIL:      %-30s → got %s, expected %s (ret=%d)\n",
				subst_tests[i].input,
				head->value ? head->value : "(null)",
				subst_tests[i].expected,
				ret);
			failed++;
		}

		// 5. Tear down — unset so tests don't bleed into each other
		if (subst_tests[i].env_key)
			unsetenv(subst_tests[i].env_key);

		free_tokens(&head);
		i++;
	}
	printf("\n%*s %d passed, %d failed, %d wrong error code of passed\n", SPACES, "QUOTE_SKIPPING", passed, failed, wrong_error_code);
	return (failed > 0);
}
