/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:14:02 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 16:50:50 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* bool	disturb_check(t_box *stack_a, long cmd, t_sorting *sort)
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
} */

void	get_head_a(t_box *stack_a, t_box *stack_b, t_sorting *sort, long turn)
{
	cmd_rotate(stack_a);
	sort->pre = RA;
	sort->tmp[turn] = RA;
	sort->a++;
	dfs_over5(stack_a, stack_b, sort, turn + 1);
	sort->a--;
	cmd_reverse(stack_a);
	return ;
}

void	get_head_b(t_box *stack_a, t_box *stack_b, t_sorting *sort, long turn)
{
	cmd_push(stack_a, stack_b);
	sort->tmp[turn] = PA;
	dfs_over5(stack_a, stack_b, sort, turn + 1);
	cmd_push(stack_b, stack_a);
	return ;
}

void	dfs_over5(t_box *stack_a, t_box *stack_b, t_sorting *sort, long t)
{
	long	cmd;

	if (t >= sort->max_turn - (sort->tail - sort->a))
		return ;
	if (sort->a >= sort->tail && stack_b->next->value == -1)
		return (add_answer(t, sort));
	if (stack_a->next->value == sort->a)
		return (get_head_a(stack_a, stack_b, sort, t));
	if (stack_b->next->value == sort->a)
		return (get_head_b(stack_a, stack_b, sort, t));
	cmd = -1;
	while (++cmd < 11)
	{
		if (check_futility(cmd, sort) || t >= sort->max_turn - 1)
			continue ;
		if (disturb_check(stack_a, cmd, sort))
			continue ;
		if (move_stack(stack_a, stack_b, cmd, true))
			continue ;
		sort->pre = cmd;
		sort->tmp[t] = cmd;
		dfs_over5(stack_a, stack_b, sort, t + 1);
		move_stack(stack_a, stack_b, cmd, false);
	}	
}

long	get_btail(t_box *stack_a, t_box *stack_b, t_pushswap *ps)
{
	t_box	*tmp;
	long	ret;

	ret = ps->a;
	while (1)
	{
		tmp = stack_b->next;
		while (ret != tmp->value && tmp->value != -1)
			tmp = tmp->next;
		if (stack_a->next->value != ret)
		{
			if (stack_a->next->next->value != ret && tmp->value != ret)
				return (ret);
		}
		ret++;
	}
}

void	all_sort(t_box *stack_a, t_box *stack_b, t_pushswap *ps, long size)
{
	t_sorting	sort;
	long		i;

	sort.max_turn = LIMIT_OVER5;
	i = -1;
	while (++i < LIMIT_OVER5)
	{
		sort.tmp[i] = -1;
		sort.ans[i] = -1;
	}
	sort.pre = ps->answer->prev->value;
	sort.size = size;
	sort.a = ps->a;
	if (stack_b->next->value != -1)
		sort.tail = get_btail(stack_a, stack_b, ps);
	else
		sort.tail = size + ps->a;
	dfs_over5(stack_a, stack_b, &sort, 0);
	ans_join(ps, &sort);
	stack_update(stack_a, stack_b, &sort);
	ps->a = sort.tail;
	ps->b = sort.tail;
}
