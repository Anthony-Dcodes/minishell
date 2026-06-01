/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlistex_tests.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:15:54 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 18:36:11 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

typedef struct s_tlistex_tests
{
    char    *input;
} t_tlistex_tests;

t_tlistex_tests tlistex_tests[] = {
	{"echo hello"},
	{"echo hello_world"},
	{"echo hello world"},
	{"echo 'single_quotes'"},
	{"echo \"double_quotes\""},
	{"cat one_pipe | ls"},
	{"cat first_pipe | second_pipe | no_more_pipe"},
	{"cat 'single' nex is pipe | \"double\" next on more pipe | ls"},
	{"hello world > file.txt | cat myname"},
	{"'every' 'word' 'in' 'single' 'quote' ' ' '|' '<' '>' '<<' '>>' 'end'"},
	{"a | b | c | d | e | f"},
	{"\"every\" \"word\" \"in\" \"double\" \"quote\" \" \" \"|\" \"<\" \">\" \"<<\" \">>\" \"end\""},
	{NULL}
};
