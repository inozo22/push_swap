/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:14:02 by nimai             #+#    #+#             */
/*   Updated: 2023/02/28 12:44:02 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_head_a(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn)
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

void	get_head_b(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn)
{
	cmd_push(stack_a, stack_b);
	sort->tmp[turn] = PA;
	dfs_over5(stack_a, stack_b, sort, turn + 1);
	cmd_push(stack_b, stack_a);
	return ;
}

void	dfs_over5(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn)
{
	long	cmd;

	if (turn >= sort->max_turn - (sort->tail - sort->a))
		return ;
	if (sort->a >= sort->tail && stack_b->next->value == -1)
		return (add_answer(turn, sort));
	if (stack_a->next->value == sort->a)
		return (get_head_a(stack_a, stack_b, sort, turn));
	if (stack_b->next->value == sort->a)
		return (get_head_b(stack_a, stack_b, sort, turn));
	cmd = -1;
	while (++cmd < 11)
	{
		if (check_futility(cmd, sort) || turn >= sort->max_turn - 1)
			continue;
		//if (disturb_check)
		if (move_stack(stack_a, stack_b, cmd, true))
			continue;
		sort->pre = cmd;
		sort->tmp[turn] = cmd;
		dfs_over5(stack_a, stack_b, sort, turn + 1);
	//	printf("how many times do dfs here?\n");
		move_stack(stack_a, stack_b, cmd, false);
	}	
}

long	get_tail(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
	t_boxes	*tmp;
	long	ret;
	
	ret = ps->a;
	while (1)//infinity loop
	{
		tmp = stack_b->next;
		while (ret != tmp->value && tmp->value != -1)
			tmp = tmp->next;
		if (stack_a->next->value != ret && stack_a->next->next->value != ret && tmp->value != ret)
		{
			printf("got_tail ====== tail :%ld\n", ret);
			return (ret);
		}
		ret++;
	}
}

void	all_sort(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, long size)
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
// koko kara kesu
/* 	i = 0;
	while (i < LIMIT_OVER5)
	{
		printf("sort.tmp[%ld]: %ld\n", i, sort.tmp[i]);
		i++;		
	} */
// koko made kesu
	sort.pre = ps->answer->prev->value;
	sort.size = size;
	sort.a = ps->a;
	if (stack_a->next->value != -1)
		sort.tail = get_tail(stack_a, stack_b, ps);
/* 	else
		sort.tail = size + ps->a; */
	dfs_over5(stack_a, stack_b, &sort, 0);
//	printf("I have been there, after dfs over5\n");//
	ans_join(ps, &sort);
//	printf("I have been there, after ansjoin\n");//
	stack_update(stack_a, stack_b, &sort);
//	printf("I have been there, after stackupdate\n");//
	ps->a = sort.tail;
//	printf("I have been there, after change ps A\n");//
	ps->b = sort.tail;
//	printf("I have been there, after change ps B\n");//
}
