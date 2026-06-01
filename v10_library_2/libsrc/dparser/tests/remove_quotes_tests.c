/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:13:41 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 08:46:47 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structs.h"
#include "macros.h"
#include "remove_quotes_tests.h"
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
	tok->len = ad_strlen(value);
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
	while (quote_remove_test[i].input != NULL)
	{
		// 1. Build a minimal token list
		head = make_word_token(quote_remove_test[i].input);
		if (!head)
		{
			printf("MALLOC ERR: %s\n", quote_remove_test[i].input);
			i++;
			continue ;
		}

		// 2. Remove quotes
		ret = remove_quotes(head);


		if (strcmp(head->value, quote_remove_test[i].expected) == 0)
		{
			if (quote_remove_test[i].expect_err == ret)
			{
				printf("OK:        %-30s → %s\n",
					quote_remove_test[i].input, head->value);
				passed++;
			}
			else
			{
				printf("OK:        %-30s → %s, wrong error code, got %d, expected %d\n",
				quote_remove_test[i].input, head->value,
				ret,
				quote_remove_test[i].expect_err);
				passed++;
				wrong_error_code++;
			}
		}
		else
		{
			printf("FAIL:      %-30s → got %s, expected %s (ret=%d)\n",
				quote_remove_test[i].input,
				head->value ? head->value : "(null)",
				quote_remove_test[i].expected,
				ret);
			failed++;
		}

		free_tokens(&head);
		i++;
	}
	printf("\n%*s %d passed, %d failed, %d wrong error code of passed\n", SPACES, "REMOVE_QUOTES", passed, failed, wrong_error_code);
	return (failed > 0);
}
