/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:06:42 by advorace          #+#    #+#             */
/*   Updated: 2026/05/23 17:27:10 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

// Skip idx list
t_skip_idxs	*create_skip_idx_node(int start_idx, int end_idx, int *ret);
void	append_skip_idx_node(t_token *head, t_skip_idxs *node);
void	free_skip_idx_list(t_token *head);

// Remove quotes
int	remove_quotes(t_token *head);
int	find_next_quote(char *str, int start, char quote_char, t_token *head);
int	remove_string_quotes(char *str, int first_quote, int second_quote, char **dest);

