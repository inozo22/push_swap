/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:47:19 by nimai             #+#    #+#             */
/*   Updated: 2023/05/02 14:24:56 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_update(t_box *stack_a, t_box *stack_b, t_sorting *sort)
{
	long	i;

	i = 0;
	while (i < sort->max_turn)
	{
		move_stack(stack_a, stack_b, sort->ans[i], true);
		i++;
	}
}

void	ans_join(t_bunch *ps, t_sorting *sort)
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
