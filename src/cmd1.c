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

bool	cmd_swap(t_boxes *box)
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

bool	cmd_rotate(t_boxes *box)
{
	t_boxes	*tmp1;
	t_boxes	*tmp2;
	t_boxes	*tmp3;

	if (box->next->next->value == -1)
		return (true);
	tmp1 = box->prev;
	tmp2 = box->next;
	tmp3 = box->next->next;
	box->next = tmp3;
	tmp3->prev = box;
	box->prev = tmp2;
	tmp2->prev = tmp1;
	tmp1->next = tmp2;
	tmp2->next = box;
	return (false);
}

bool	cmd_reverse(t_boxes *box)
{
	t_boxes	*tmp1;
	t_boxes	*tmp2;
	t_boxes	*tmp3;

	if (box->next->next->value == -1)
		return (true);
	tmp1 = box->prev;
	tmp2 = box->next;
	tmp3 = box->prev->prev;
	box->next = tmp1;
	tmp1->prev = box;
	box->prev = tmp3;
	tmp2->prev = tmp1;
	tmp1->next = tmp2;
	tmp3->next = box;
	return (false);
}

bool	cmd_push(t_boxes *dst, t_boxes *src)
{
	t_boxes	*dst_tmp;
	t_boxes	*src_tmp1;
	t_boxes	*src_tmp2;

	if (src->next->value == -1)
		return (true);
	dst_tmp = dst->next;
	src_tmp1 = src->next;
	src_tmp2 = src->next->next;
	src->next = src_tmp2;
	src_tmp2->prev = src;
	dst->next = src_tmp1;
	src_tmp1->next = dst_tmp;
	dst_tmp->prev = src_tmp1;
	src_tmp1->prev = dst;
	return (false);
}
