/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:38:08 by nimai             #+#    #+#             */
/*   Updated: 2023/02/20 17:42:47 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_answer(long turn, t_sorting *sort)
{
	long	i;

	sort->max_turn = turn;
	i = 0;
	while (i < turn)
	{
		sort->ans[i] = sort->tmp[i];
		i++;
	}
}

void	get_answer(t_pushswap *ps, t_sorting *sort)
{
	long	i;

	i = 0;
	while (i < sort->max_turn)
	{
		add_box(ps->answer, sort->ans[i]);
		i++;
	}
}

void	update_answer(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort)
{
	long	i;

	i = 0;
	while (i < sort->max_turn)
	{
		move_stack(stack_a, stack_b, sort->ans[i], true);
		i++;
	}

}


void	dfs(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn)
{
	long	command;

	if (turn >= sort->max_turn)
		return ;//de repente si es igual que el límite, termina la función
	if (stack_b->next->value == -1 && is_sorted(stack_a))
		return (add_answer(turn, sort));
	command = 0;
	while (command < 11)
	{
		if (turn >= sort->max_turn)
			continue;
		if (move_stack(stack_a, stack_b, command, true))
			continue;
		sort->pre = command;
		sort->tmp[turn] = command;
		dfs(stack_a, stack_b, sort, turn + 1);
		move_stack(stack_a, stack_b, command, false);
	}
}

void	sort_less6(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
	t_sorting	sort;
	long		i;

	sort.max_turn = LIMIT_LESS6;
	i = 0;
	while (i < LIMIT_LESS6)
	{
		sort.tmp[i] = -1;
		sort.ans[i] = -1;
		i++;
	}
	sort.pre = -1;
	dfs(stack_a, stack_b, &sort, 0);
	get_answer(ps, &sort);
	update_answer(stack_a, stack_b, &sort);
}
