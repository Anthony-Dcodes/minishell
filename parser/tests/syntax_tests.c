/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:27:29 by advorace          #+#    #+#             */
/*   Updated: 2026/05/23 11:51:51 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_tests.h"
#include "../tokenizer.h"
#include "macros.h"
#include <stdio.h>

int main(void)
{
    int i;
    int result;
    int passed;
    int failed;
	t_token *head;

    i = 0;
    passed = 0;
    failed = 0;
    while (tests[i].input != NULL)
    {
        head = NULL;
		if (tokenizer(&head, tests[i].input) != ERR_OK)
		{
			printf("TOKENIZER ERR: %s\n", tests[i].input);
			i++;
			continue ;
		}
		result = syntax_checker(head);
		if (result == tests[i].expected)
		{
			printf("OK:   %s\n", tests[i].input);
			passed++;
		}
		else
		{
			printf("FAIL: %s (expected %d got %d)\n",
				tests[i].input, tests[i].expected, result);
			failed++;
		}
		free_tokens(&head);  // whatever your free function is called
		i++;
    }
    printf("\n%*s %d passed, %d failed\n", SPACES, "SYNTAX", passed, failed);
	return (0);
}
