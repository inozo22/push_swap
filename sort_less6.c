/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:38:08 by nimai             #+#    #+#             */
/*   Updated: 2023/02/22 17:37:38 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_answer(long turn, t_sorting *sort)
{
	long	i;

	sort->max_turn = turn;
	i = 0;
	printf("----turn %ld----\n", turn);
	while (i < turn)
	{
		sort->ans[i] = sort->tmp[i];
		printf("sort->ans[%ld]: %ld\n", i, sort->ans[i]);
		i++;
	}
	printf("----turn %ld----\n\n", turn);
}

void	get_answer(t_pushswap *ps, t_sorting *sort)
{
	long	i;

	i = -1;
	while (++i < sort->max_turn)
	{
		add_box(ps->answer, sort->ans[i]);
	}
/* 	printf("para ver la situacion GETANSWER\n");
	print_stacka(stack_a); */
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
/* 	printf("para ver la situacion UPDATE_STACKA\n");
	print_stacka(stack_a); */
}

bool	check_futility(t_sorting *sort, long cmd)
{
	if (cmd == SA && (sort->pre == SA || sort->pre == SS))
		return (true);
	if (cmd == SB && (sort->pre == SB || sort->pre == SS))
		return (true);
	if (cmd == SS && (sort->pre == SA || sort->pre == SB || sort->pre == SS))
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
	if (cmd == PA && (sort->pre == PB))
		return (true);
	if (cmd == PB && (sort->pre == PA))
		return (true);
	return (false);
}


void	dfs(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn)
{
	long	command;
	long i;//ato de kesu

	i = 0;
	if (turn >= sort->max_turn && command != '\0')
	{
//		move_stack(stack_a, stack_b, command, false);//para que llegue hasta el movimiento
		return ;
	}

	if (stack_b->next->value == -1)
	{
		if (is_sorted(stack_a))
		{
			printf("when is sorted\n");
			while (i < sort->max_turn)
			{
				printf("sort->ans[%ld]: %ld\n", i, sort->ans[i]);
				i++;
			}
			printf("para ver la situacion IS SORTED???\n");
			print_stacka(stack_a);
			return (add_answer(turn, sort));
		}
	}
	command = -1;
	while (++command < 11)
	{
		if (check_futility(sort, command) || turn >= sort->max_turn)//cut when these are true
		{
			command++;
			continue ;
		}
		if (move_stack(stack_a, stack_b, command, true))
		{
			command++;
			continue ;
		}
		sort->pre = command;
		sort->tmp[turn] = command;
		dfs(stack_a, stack_b, sort, (turn + 1));
		move_stack(stack_a, stack_b, command, false);//reset this movement and go to the next cmd
		//command++;
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
	printf("para ver la situacion, despues de dfs\n");
	print_stacka(stack_a);
	get_answer(ps, &sort);
	update_stack(stack_a, stack_b, &sort);//iru?
	printf("para ver la situacion, desupues de update_stack\n");
	print_stacka(stack_a);
/* 	printf("print sort.tmp:\n");
	i = 0;
	while (i < sort.max_turn - 1)
	{
		printf("%ld\n", sort.tmp[i]);
		i++;
	}*/
	/* printf("print sort.ans:\n");
	i = 0;
	while (sort.ans[i] != -1)
	{
		printf("%ld\n", sort.ans[i]);
		i++;
	} *//*
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
