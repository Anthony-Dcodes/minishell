/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:52:41 by advorace          #+#    #+#             */
/*   Updated: 2026/05/20 10:15:52 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"
#include "tokenizer_tests.h"
#include <stdio.h>
#include "macros.h"

int main(void)
{
	int		i;
	t_token *head;
	t_token *temp_head;
	int		ret;
	int		total_tokens;
	int		passed = 0;
	int		failed = 0;

	i = 0;
	while (tokenize_tests[i].token != NULL)
	{
		//printf("tokenize_tests[i]: '%s'\n", tokenize_tests[i]);
		head = NULL;
		total_tokens = 0;
		ret = tokenizer(&head, tokenize_tests[i].token);
		if (ret != ERR_OK)
		{
			printf("error: %d\n", ret);
			return 1;
		}
		temp_head = head;
		//printf("done\n\n");
		while (temp_head != NULL)
		{
			++total_tokens;
			temp_head = temp_head->next;
		}
		if (total_tokens != tokenize_tests[i].number_of_tokens)
		{
			printf("FAIL:		expected: %d, got: %d\n", tokenize_tests[i].number_of_tokens, total_tokens);
			printf("	Test: %s\n", tokenize_tests[i].token);
			printf("	Tokenizer:\n");
			temp_head = head;
			while (temp_head)
			{
				printf("	%s\n", temp_head->value);
				temp_head = temp_head->next;
			}
			++failed;
		}
		else
		{
			printf("OK:		expected: %d, got: %d\n", tokenize_tests[i].number_of_tokens, total_tokens);
			++passed;
		}
		++i;
		free_tokens(&head);
	}
	printf("\n%*s %d passed, %d failed\n", SPACES, "TOKENIZER", passed, failed);
	return (failed > 0);
}
