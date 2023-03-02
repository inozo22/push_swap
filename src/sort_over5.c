/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 18:21:44 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_a_len(t_box *stack_a, t_bunch *ps)
{
	long	ret;
	long	max;
	t_box	*tmp;

	ret = 0;
	max = -ARGLIMIT - 10;
	tmp = stack_a->next;
	while (max - ps->a + 1 != ret && tmp->value)
	{
		ret++;
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (ret);
}

bool	stay_b(t_box *stack_b, t_bunch *ps, long size)
{
	ps->b++;
	if (size == 1)
	{
		return (true);
	}
	if (stack_b->prev->value == ps->b)
		ps->b++;
	cmd_rotate(stack_b);
	add_box(ps->answer, RB);
	return (false);
}

void	settle_top(t_box *stack_a, t_box *stack_b, t_bunch *ps)
{
	long	i;

	i = -1;
	while ((++i + ps->a) < ps->b)
	{
		if (stack_b->prev->value == ps->b - i - 1)
			move_add_box(stack_a, stack_b, ps, RRB);
		else if (stack_b->prev->prev->value == ps->b - i - 1)
		{
			move_add_box(stack_a, stack_b, ps, RRB);
			move_add_box(stack_a, stack_b, ps, RRB);
		}
		else if (stack_b->next->value == ps->b - i - 1)
		{
			move_add_box(stack_a, stack_b, ps, PA);
			ps->a++;
		}
	}
	while (stack_a->next->value == ps->a)
	{
		move_add_box(stack_a, stack_b, ps, RA);
		ps->a++;
	}
}

void	settle_half(t_box *stack_a, t_box *stack_b, t_bunch *ps)
{
	long	i;
	long	size_b;

	i = -1;
	size_b = 0;
	while (++i < ps->size && size_b < (ps->size / 2))
	{
		while (stack_b->next->value == ps->b)
		{
			if (stay_b(stack_b, ps, size_b))
				break ;
		}
		if (stack_b->next->value == ps->b + 1)
		{
			if (!b_left(stack_b, ps) && size_b > 1)
				move_add_box(stack_a, stack_b, ps, RB);
		}
		if (stack_a->next->value < (ps->size / 2))
		{
			move_add_box(stack_a, stack_b, ps, PB);
			size_b++;
		}
		else
			move_add_box(stack_a, stack_b, ps, RA);
	}
}

void	sort_over5(t_box *stack_a, t_box *stack_b, t_bunch *ps)
{
	long	size;

	settle_half(stack_a, stack_b, ps);
	while (ps->a != ps->size)
	{
		size = stack_len(stack_b);
		while (size > SORT_SIZE)
		{
			b_qsort(stack_a, stack_b, ps, size);
			size = stack_len(stack_b);
		}
		if (size)
			all_sort(stack_a, stack_b, ps, size);
		size = get_a_len(stack_a, ps);
		while (size && size <= SORT_SIZE)
		{
			all_sort(stack_a, stack_b, ps, size);
			size = get_a_len(stack_a, ps);
		}
		if (size)
			a_qsort(stack_a, stack_b, ps, size);
	}
}
