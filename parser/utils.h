/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:13:36 by advorace          #+#    #+#             */
/*   Updated: 2026/05/22 13:14:01 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h>

// String utils
size_t	ft_strlen(const char *s);
int	ft_isspace(char c);
int	ft_isalnum(int c);
int	get_string(int start, int end, char *src, char **dst);