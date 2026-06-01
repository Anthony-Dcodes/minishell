/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:06:42 by advorace          #+#    #+#             */
/*   Updated: 2026/05/25 10:40:06 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Remove quotes
int	remove_quotes(t_token *head);
int	find_next_quote(char *str, int start, char quote_char, t_token *head);
int	remove_string_quotes(char *str, int first_quote,
		int second_quote, char **dest, t_token *head);
