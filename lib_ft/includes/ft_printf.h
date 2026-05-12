/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:30:28 by advorace          #+#    #+#             */
/*   Updated: 2025/07/15 21:45:51 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf.h"
# include <unistd.h>
# include "libft.h"

int			ft_printf(const char *format, ...);
int			handle_sc_formats(char format_specifier, va_list *args);
int			common_print(char *str);
char		*uiota(unsigned int n);
int			handle_diu_formats(char format_specifier, va_list *args);
char		*int_to_hex(int num);
int			handle_xxp_formats(char format_specifier, va_list *args);
char		*unsigned_long_to_hex(void *prt);

#endif
