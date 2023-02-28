/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:43:42 by nimai             #+#    #+#             */
/*   Updated: 2023/02/28 09:57:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
//	printf("* swap between %ld and %ld\n", box->next->value, box->next->next->value);
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
//	printf("* rotate between %ld and %ld\n", box->prev->value, box->next->value);
	return (false);
}

bool	cmd_reverse(t_boxes *box)
{
	t_boxes	*tmp1;
	t_boxes	*tmp2;
	t_boxes	*tmp3;

	if (box->next->next->value == -1)
	{
//		printf("---return reverse\n");
		return (true);
	}
	tmp1 = box->prev->prev;
	tmp2 = box->prev;
	tmp3 = box->next;
	box->next = tmp2;
	tmp2->next = tmp3;
	tmp3->prev = tmp2;
	tmp2->prev = box;
	box->prev = tmp1;
	tmp1->next = box;
//	printf("* reverse between %ld and %ld\n", box->prev->value, box->next->value);
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
//	printf("* push between dest:%ld and src:%ld\n", dst->next->value, src->next->value);//
	src->next = src_tmp2;
	src_tmp2->prev = src;
	dst->next = src_tmp1;
	src_tmp1->next = dst_tmp;
	dst_tmp->prev = src_tmp1;
	src_tmp1->prev = dst;

	return (false);
}
