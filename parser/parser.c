/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:11:29 by advorace          #+#    #+#             */
/*   Updated: 2026/03/16 22:13:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

int ft_parsecmd(t_s *s, char *src, t_listex **dst, char **envp)
{
	t_tokens	**tokens;
	int			ret;

	ret = ERR_OK;
	ret = lexing(tokens);
}
