/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 09:50:44 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	b_left(t_boxes *stack_b, t_pushswap *ps)
{
	t_boxes	*tmp;
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

long	get_a_len(t_boxes *stack_a, t_pushswap *ps)
{
	long	ret;
	long	max;
	t_boxes	*tmp;

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

void	move_add_box(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, long cmd)
{
	if (cmd == SA)
		cmd_swap(stack_a);
	else if (cmd == SB)
		cmd_swap(stack_b);
	else if (cmd == PA)
		cmd_push(stack_a, stack_b);
	else if (cmd == PB)
		cmd_push(stack_b, stack_a);
	else if (cmd == RA)
		cmd_rotate(stack_a);
	else if (cmd == RB)
		cmd_rotate(stack_b);
	else if (cmd == RRA)
		cmd_reverse(stack_a);
	else if (cmd == RRB)
		cmd_reverse(stack_b);
	add_box(ps->answer, cmd);
}

void	a_qsort(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, long size)
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

void	b_qsort(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, long size)
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

long	stack_len(t_boxes *stack)
{
	long	ret;
	t_boxes	*tmp;

	ret = 0;
	tmp = stack;
	while (tmp->next->value != -1)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}

bool	stay_b(t_boxes *stack_b, t_pushswap *ps, long size)
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

void	settle_top(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
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

void	settle_half(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
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

void	sort_over5(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
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

