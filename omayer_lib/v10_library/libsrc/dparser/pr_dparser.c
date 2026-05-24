/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_dparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:32:16 by omayer            #+#    #+#             */
/*   Updated: 2026/05/22 12:28:27 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pr_dparser.h"
#include "unistd.h"

// Toto je fce kterou volas

int	ft_eparsermain(char *src, t_listex ***dst, char **envp)
{
	t_listex		**result;

	ft_enewlistexarr2(&result, 1);
	ft_enewlistex2(result[0], 1, TRUE);
	result[0]->size = 0;
	if ((src[0] == '#') && (envp))
		ft_elistaddex2(result[0], "exit");
	else
	{
		ft_elistaddex2(result[0], src);
	}
	write(1, "Hi from external parser!/n", 24);
	sleep(5);
	*dst = result;
	return (SUCCESS);
}
