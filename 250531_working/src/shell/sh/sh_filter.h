/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_filter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:06:03 by omayer            #+#    #+#             */
/*   Updated: 2026/03/18 08:36:03 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_FILTER_H
# define SH_FILTER_H

# include "../../../mshell.h"

int	ft_argfilter(t_s *s, t_listex *src_filtered);
int	ft_parsecmdfilter(t_s *s, t_listex ***result, t_listex **parsed_exp);

#endif