/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:31 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 18:21:21 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	converge_box(t_box *answer, long cmd)
{
	t_box	*tmp;

	tmp = answer->next->next;
	free(answer->next);
	answer->next = NULL;
	answer->value = cmd;
	answer->next = tmp;
	tmp->prev = answer;
}

void	combine_cmd(t_box *answer)
{
	t_box	*tmp;

	tmp = answer->next;
	while (tmp->value != -1)
	{
		if (tmp->value == RA && tmp->next->value == RB)
			converge_box(tmp, RR);
		if (tmp->value == RB && tmp->next->value == RA)
			converge_box(tmp, RR);
		if (tmp->value == SA && tmp->next->value == SB)
			converge_box(tmp, SS);
		if (tmp->value == SB && tmp->next->value == SA)
			converge_box(tmp, SS);
		if (tmp->value == RRA && tmp->next->value == RRB)
			converge_box(tmp, RRR);
		if (tmp->value == RRB && tmp->next->value == RRA)
			converge_box(tmp, RRR);
		tmp = tmp->next;
	}	
}

//to reset previous movement 
long	recover(long command)
{
	if (command == PA)
		return (PB);
	if (command == PB)
		return (PA);
	if (command == RA)
		return (RRA);
	if (command == RB)
		return (RRB);
	if (command == RR)
		return (RRR);
	if (command == RRA)
		return (RA);
	if (command == RRB)
		return (RB);
	if (command == RRR)
		return (RR);
	return (command);
}

void	move_add_box(t_box *stack_a, t_box *stack_b, t_bunch *ps, long cmd)
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
//after move, record the command
	add_box(ps->answer, cmd);
}

bool	move_stack(t_box *stack_a, t_box *stack_b, long cmd, bool exe)
{
	if (exe == false)
		cmd = recover(cmd);
	if (cmd == SA)
		return (cmd_swap(stack_a));
	else if (cmd == SB)
		return (cmd_swap(stack_b));
	else if (cmd == SS)
		return (cmd_ss(stack_a, stack_b));
	else if (cmd == PA)
		return (cmd_push(stack_a, stack_b));
	else if (cmd == PB)
		return (cmd_push(stack_b, stack_a));
	else if (cmd == RA)
		return (cmd_rotate(stack_a));
	else if (cmd == RB)
		return (cmd_rotate(stack_b));
	else if (cmd == RR)
		return (cmd_rr(stack_a, stack_b));
	else if (cmd == RRA)
		return (cmd_reverse(stack_a));
	else if (cmd == RRB)
		return (cmd_reverse(stack_b));
	else if (cmd == RRR)
		return (cmd_rrr(stack_a, stack_b));
	return (true);
}
