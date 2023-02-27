/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:31 by nimai             #+#    #+#             */
/*   Updated: 2023/02/27 16:49:21 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	recover(long command)
{
	if (command == PA)
	{
		printf("do recover: PA\n");
		return (PB);
	}
	if (command == PB)
	{
		printf("do recover: PB\n");
		return (PA);
	}
	if (command == RA)
	{
		printf("do recover: RA\n");
		return (RRA);
	}

	if (command == RB)
	{
		printf("do recover: RB\n");
		return (RRB);
	}
	if (command == RR)
	{
		printf("do recover: RR\n");
		return (RRR);
	}
	if (command == RRA)
	{
		printf("DO recover:RRA\n");
		return (RA);
	}
	if (command == RRB)
	{
		printf("DO recover: RRB\n");
		return (RB);
	}
	if (command == RRR)
	{
		printf("DO recover: RRR\n");
		return (RR);
	}
	printf("do recover: PUSH\n");
	return (command);
}

bool	move_stack(t_boxes *stack_a, t_boxes *stack_b, long cmd, bool exe)
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
	{
		printf("cmd_%ld\n", cmd);
		return (cmd_reverse(stack_a));			
	}
	else if (cmd == RRB)
	{
		printf("cmd_%ld\n", cmd);
		return (cmd_reverse(stack_b));		
	}
	else if (cmd == RRR)
	{
		printf("cmd_%ld\n", cmd);
		return (cmd_rrr(stack_a, stack_b));
	}
	return (true);
}
