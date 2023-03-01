/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:47:19 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 07:12:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_update(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort)
{
	long	i;

	i = 0;
	while (i < sort->max_turn)
	{
		move_stack(stack_a, stack_b, sort->ans[i], true);
		i++;
	}
}

void	ans_join(t_pushswap *ps, t_sorting *sort)
{
	long	i;

	i = 0;
	while (i < sort->max_turn)
	{
		add_box(ps->answer, sort->ans[i]);
		i++;
	}
}

bool	check_futility(long cmd, t_sorting *sort)
{
	if (cmd == SA && (sort->pre == SA || sort->pre == SB || sort->pre == SS))
		return (true);
	if (cmd == SB && (sort->pre == SA || sort->pre == SB || sort->pre == SS))
		return (true);
	if (cmd == SS && (sort->pre == SA || sort->pre == SB || sort->pre == SS))
		return (true);
	if (cmd == PA && sort->pre == PB)
		return (true);
	if (cmd == PB && sort->pre == PA)
		return (true);
	if (cmd == RA && (sort->pre == RRA || sort->pre == RRR))
		return (true);
	if (cmd == RB && (sort->pre == RRB || sort->pre == RRR))
		return (true);
	if (cmd == RR && (sort->pre == RRA || sort->pre == RRB || sort->pre == RRR))
		return (true);
	if (cmd == RRA && (sort->pre == RA || sort->pre == RR))
		return (true);
	if (cmd == RRB && (sort->pre == RB || sort->pre == RR))
		return (true);
	if (cmd == RRR && (sort->pre == RA || sort->pre == RB || sort->pre == RR))
		return (true);
	return (false);
}

void	add_answer(long turn, t_sorting *sort)
{
	long	i;

	sort->max_turn = turn;
	i = 0;
	while (i < sort->max_turn)
	{
		sort->ans[i] = sort->tmp[i];
		i++;
	}
}

void	dfs(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn)
{
	long	cmd;

	if (turn >= sort->max_turn)
		return ;
	if (stack_b->next->value == -1 && is_sorted(stack_a))
		return (add_answer(turn, sort));
	cmd = -1;
	while (++cmd < 11)
	{
		if (check_futility(cmd, sort) || turn >= sort->max_turn)
			continue ;
		if (move_stack(stack_a, stack_b, cmd, true))
			continue ;
		sort->pre = cmd;
		sort->tmp[turn] = cmd;
		dfs(stack_a, stack_b, sort, turn + 1);
		move_stack(stack_a, stack_b, cmd, false);
	}
}

void	sort_less6(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
	t_sorting	sort;
	long		i;
	long		turn;

	turn = 0;
	sort.max_turn = LIMIT_LESS6;
	i = -1;
	while (++i < LIMIT_LESS6)
	{
		sort.tmp[i] = -1;
		sort.ans[i] = -1;
	}
	sort.pre = -1;
	dfs(stack_a, stack_b, &sort, turn);
	ans_join(ps, &sort);
	stack_update(stack_a, stack_b, &sort);
}
