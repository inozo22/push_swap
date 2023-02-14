/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:43:42 by nimai             #+#    #+#             */
/*   Updated: 2023/02/14 13:43:42 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_boxes *box)
{
	t_boxes	*tmp1;
	t_boxes	*tmp2;
	t_boxes	*tmp3;

	if (box->next->next->value == -1)
		return (true);
	tmp1 = box->next;
	tmp2 = box->next->next;
	tmp3 = box->next->next->next;
	box->next = tmp2;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
	tmp3->prev = tmp1;
	tmp1->prev = tmp2;
	tmp2->prev = box;
	return (false);
}
