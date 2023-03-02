/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 18:21:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	disturb_check(t_box *stack_a, long cmd, t_sorting *sort)
{
	if (cmd == SA && (stack_a->next->next->value >= sort->tail))
		return (true);
	if (cmd == SS && (stack_a->next->next->value >= sort->tail))
		return (true);
	if (cmd == RA && (stack_a->next->value >= sort->tail))
		return (true);
	if (cmd == RR && (stack_a->next->value >= sort->tail))
		return (true);
	return (false);
}

bool	b_left(t_box *stack_b, t_bunch *ps)
{
	t_box	*tmp;
	long	start;

	start = stack_b->value;
	tmp = stack_b->next;
	while (tmp->value != start)
	{
		if (tmp->value == ps->b)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	a_qsort(t_box *stack_a, t_box *stack_b, t_bunch *ps, long size)
{
	long	i;

	i = -1;
	while (++i < size)
	{
		if (stack_b->prev->value == ps->a)
			move_add_box(stack_a, stack_b, ps, RRB);
		if (stack_b->next->next->value == ps->a)
			move_add_box(stack_a, stack_b, ps, SB);
		if (stack_b->next->value == ps->a && (--i || 1))
			move_add_box(stack_a, stack_b, ps, PA);
		if (stack_a->next->next->value == ps->a)
		{
			if (stack_a->next->value == ps->a + 1)
				move_add_box(stack_a, stack_b, ps, SA);
		}
		if (stack_a->next->value == ps->a)
		{
			move_add_box(stack_a, stack_b, ps, RA);
			++ps->a;
		}
		else
			move_add_box(stack_a, stack_b, ps, PB);
	}
}

void	b_qsort(t_box *stack_a, t_box *stack_b, t_bunch *ps, long size)
{
	long	i;
	long	pivot;
	long	size_b;

	i = -1;
	size_b = size;
	pivot = ps->a + (size - 1) / 2;
	while (++i < size)
	{
		if (stack_b->next->value == ps->a && size_b-- && ++ps->a)
		{
			move_add_box(stack_a, stack_b, ps, PA);
			move_add_box(stack_a, stack_b, ps, RA);
		}
		else if (stack_b->next->value > pivot && size_b--)
			move_add_box(stack_a, stack_b, ps, PA);
		else
			move_add_box(stack_a, stack_b, ps, RB);
	}
}

long	stack_len(t_box *stack)
{
	long	ret;
	t_box	*tmp;

	ret = 0;
	tmp = stack;
	while (tmp->next->value != -1)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}
