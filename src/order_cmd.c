/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:31 by nimai             #+#    #+#             */
/*   Updated: 2023/02/27 13:51:15 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	recover(long command)
{
	if (command == PA)
	{
//		printf("do recover: %ld\n", command);
		return (PB);
	}
	if (command == PB)
	{
//		printf("do recover: %ld\n", command);
		return (PA);
	}
	if (command == RA)
	{
//		printf("do recover: %ld\n", command);
		return (RRA);
	}

	if (command == RB)
	{
//		printf("do recover: %ld\n", command);
		return (RRB);
	}
	if (command == RR)
	{
//		printf("do recover: %ld\n", command);
		return (RRR);
	}
	if (command == RRA)
	{
		printf("do recover: %ld\n", command);
		return (RA);
	}
	if (command == RRB)
	{
		printf("do recover: %ld\n", command);
		return (RB);
	}
	if (command == RRR)
	{
		printf("do recover: %ld\n", command);
		return (RR);
	}
//	printf("do recover: %ld\n", command);
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
		return (cmd_reverse(stack_a));
	else if (cmd == RRB)
		return (cmd_reverse(stack_b));
	else if (cmd == RRR)
		return (cmd_rr(stack_a, stack_b));
	return (true);
}
