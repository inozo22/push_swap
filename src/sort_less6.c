/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:38:08 by nimai             #+#    #+#             */
/*   Updated: 2023/02/21 17:34:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_answer(long turn, t_sorting *sort)
{
	long	i;

	sort->max_turn = turn;
	i = 0;
	printf("-------------\n");
	while (i < turn)
	{
		sort->ans[i] = sort->tmp[i];
		printf("sort->ans[%ld]: %ld\n", i, sort->ans[i]);
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

void	update_stack(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort)
{
	long	i;

	i = 0;
	while (i < sort->max_turn)
	{
		move_stack(stack_a, stack_b, sort->ans[i], true);
		i++;
	}
}

bool	check_futility(t_sorting *sort, long command)
{
	if (command == SA && (sort->pre == SA || sort->pre == SB ||sort->pre == SS))
		return (true);
	if (command == SB && (sort->pre == SA || sort->pre == SB || sort->pre == SS))
		return (true);
	if (command == SS && (sort->pre == SA || sort->pre == SB || sort->pre == SS))
		return (true);
	if (command == RA && (sort->pre == RRA || sort->pre == RRR))
		return (true);
	if (command == RB && (sort->pre == RRB || sort->pre == RRR))
		return (true);
	if (command == RR && (sort->pre == RRA || sort->pre == RRB || sort->pre == RRR))
		return (true);
	if (command == RRA && (sort->pre == RA || sort->pre == RR))
		return (true);
	if (command == RRB && (sort->pre == RB || sort->pre == RR))
		return (true);
	if (command == RRR && (sort->pre == RA || sort->pre == RB || sort->pre == RR))
		return (true);
	if (command == PA && (sort->pre == PB))
		return (true);
	if (command == PB && (sort->pre == PA))
		return (true);
	return (false);
}


void	dfs(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn)
{
	long	command;

	if (turn >= sort->max_turn)
		return ;
	if (stack_b->next->value == -1 && is_sorted(stack_a))
	{
		return (add_answer(turn, sort));
	}
	command = -1;
	while (++command < 11)
	{
		if (check_futility(sort, command) || turn >= sort->max_turn)
			continue ;
		if (move_stack(stack_a, stack_b, command, true))
			continue ;
		sort->pre = command;
		sort->tmp[turn] = command;
		dfs(stack_a, stack_b, sort, (turn + 1));
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
	update_stack(stack_a, stack_b, &sort);//iru?
/* 	printf("print sort.tmp:\n");
	i = 0;
	while (i < sort.max_turn - 1)
	{
		printf("%ld\n", sort.tmp[i]);
		i++;
	}
	printf("print sort.ans:\n");
	i = 0;
	while (sort.ans[i] != -1)
	{
		printf("%ld\n", sort.ans[i]);
		i++;
	}
	printf("print ps->answer:\n");
	i = 1;
	while (ps->answer->value != -1)
	{
		printf("%ld\n", ps->answer->value);
		i++;
	}
	printf("print ps->answer:\n");
	printf("%ld\n", ps->answer->value); */
}
