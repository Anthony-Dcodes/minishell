/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tlistx.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:40:21 by advorace          #+#    #+#             */
/*   Updated: 2026/05/27 11:13:03 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	get_n_pipes(t_token *head);
int	fill_tlistx(t_token *tokens, t_listex ***listex);
int	assign_quote(t_listex *listex, int quote);
