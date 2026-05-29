/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:40:21 by advorace          #+#    #+#             */
/*   Updated: 2026/05/29 10:09:50 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "structs.h"

int	get_n_pipes(t_token *head);
int	fill_tlistx(t_token *tokens, t_listex ***listex);
int	assign_quote(t_listex *listex, int quote);
int	allocate_t_listex_mem(t_listex ***listex, t_token *head);
int	assing_string(t_listex *listex, char *str, int i);
void assign_size(t_listex *listex, int size);
int	get_n_tokens_before_next_pipe(t_token *head, int nth_pipe);
void	print_t_listex(t_listex ***head);
