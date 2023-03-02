/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:47:19 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 16:28:03 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dfs(t_box *stack_a, t_box *stack_b, t_sorting *sort, long turn)
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

void	sort_less6(t_box *stack_a, t_box *stack_b, t_pushswap *ps)
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
