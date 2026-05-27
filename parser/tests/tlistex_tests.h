/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlistex_tests.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:15:54 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 14:22:22 by advorace         ###   ########.fr       */
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
	{NULL}
};
