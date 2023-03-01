/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 07:23:46 by nimai            ###   ########.fr       */
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

void	a_qsort(t_boxes *stack_a, t_boxes * stack_b, t_pushswap *ps, long size)
{
	long	i;

	i = -1;
	while (++i < size)
	{
		if (stack_b->prev->value == ps->a)
		{
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);	
		}
		if (stack_b->next->next->value == ps->a)
		{
			cmd_swap(stack_b);
			add_box(ps->answer, SB);	
		}
		if (stack_b->next->value == ps->a && (--i || 1))
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);	
		}
		if (stack_a->next->next->value == ps->a && stack_a->next->value == ps->a + 1)
		{
			cmd_swap(stack_a);
			add_box(ps->answer, SA);	
		}
		if (stack_a->next->value == ps->a)
		{
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);
			++ps->a;
		}
		else
		{
			cmd_push(stack_b, stack_a);
			add_box(ps->answer, PB);	
		}
	}
}


void	b_qsort(t_boxes *stack_a, t_boxes * stack_b, t_pushswap *ps, long size)
{
	long	i;
	long	pivot;
	long	size_b;
//	long	size_a;
	
	i = -1;
	size_b = size;
//	size_a = 0;
	pivot = ps->a + (size - 1) / 2;
	while (++i < size)
	{
		if (stack_b->next->value == ps->a && size_b-- && ++ps->a)
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);	
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);
		}
		else if (stack_b->next->value > pivot && size_b--/*  && ++size_a */)
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);				
		}
		else
		{
			cmd_rotate(stack_b);
			add_box(ps->answer, RB);
		}
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
		{
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);
		}
		else if (stack_b->prev->prev->value == ps->b - i - 1)
		{
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);
		}
		else if (stack_b->next->value == ps->b - i - 1)//
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);
			ps->a++;
		}
	}
	while (stack_a->next->value == ps->a)
	{
		cmd_rotate(stack_a);
		add_box(ps->answer, RA);
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
				break;
		}
		if (stack_b->next->value == ps->b + 1 && !b_left(stack_b, ps) && size_b > 1)
		{
			cmd_rotate(stack_b);
			add_box(ps->answer, RB);			
		}
		if (stack_a->next->value < (ps->size / 2))
		{
			cmd_push(stack_b, stack_a);
			add_box(ps->answer, PB);
			size_b++;
		}
		else
		{
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);
		}
	}
}

void	sort_over5(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
	long	size;

	settle_half(stack_a, stack_b, ps);
	while (ps->a != ps->size)
	{
		while ((size = stack_len(stack_b)) > SORT_SIZE)
		{
			b_qsort(stack_a, stack_b, ps, size);
		}
		if (size)
		{
			all_sort(stack_a, stack_b, ps, size);
		}
		while ((size = get_a_len(stack_a, ps)) && size <= SORT_SIZE)
		{
			all_sort(stack_a, stack_b, ps, size);
		}
		if (size)
		{
			a_qsort(stack_a, stack_b, ps, size);
		}
	}
}

