/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:52:41 by advorace          #+#    #+#             */
/*   Updated: 2026/05/19 18:10:54 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"
#include "tokenizer_tests.h"
#include <stdio.h>

int main(void)
{
	int		i;
	t_token *head;
	t_token *temp_head;
	int		ret;
	int		total_tokens;

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
			printf("Tokenizer test: %d failed, tokenizer token count: %d, should be: %d\n", i, total_tokens, tokenize_tests[i].number_of_tokens);
			printf("	Test: %s\n", tokenize_tests[i].token);
			printf("	Tokenizer:\n");
			temp_head = head;
			while (temp_head)
			{
				printf("	%s\n", temp_head->value);
				temp_head = temp_head->next;
			}
		}
		else 
		{
			printf("Tokenizer test: %d passed, tokenizer token count: %d, should be: %d\n", i, total_tokens, tokenize_tests[i].number_of_tokens);
		}
		++i;
		free_tokens(&head);
	}
	return 0;
}