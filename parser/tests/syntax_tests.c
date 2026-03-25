/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:27:29 by advorace          #+#    #+#             */
/*   Updated: 2026/03/25 22:49:14 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_tests.h"

int main(void)
{
    int i;
    int result;
    int passed;
    int failed;
	t_token *head;
	int		ret;

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
		result = check_syntax(head);
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
		//free_token_list(head);  // whatever your free function is called
		i++;
    }
    printf("\n%d passed, %d failed\n", passed, failed);
}
