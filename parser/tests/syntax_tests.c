/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:27:29 by advorace          #+#    #+#             */
/*   Updated: 2026/03/22 18:28:00 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_tests.h"

int main(void)
{
    int i;
    int result;
    int passed;
    int failed;

    i = 0;
    passed = 0;
    failed = 0;
    while (tests[i].input != NULL)
    {
        result = check_syntax(tokenize(tests[i].input));
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
        i++;
    }
    printf("\n%d passed, %d failed\n", passed, failed);
}
