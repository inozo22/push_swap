/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:27:31 by nimai             #+#    #+#             */
/*   Updated: 2023/02/22 12:49:39 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

bool	move_stack(t_boxes *stack_a, t_boxes *stack_b, long command, bool exe)
{
	if (!exe)
		command = recover(command);
	if (command == SA)
		return (cmd_swap(stack_a));
	if (command == SB)
		return (cmd_swap(stack_b));
	if (command == SS)
		return (cmd_ss(stack_a, stack_b));
	if (command == PA)
		return (cmd_push(stack_a, stack_b));
	if (command == PB)
		return (cmd_push(stack_b, stack_a));
	if (command == RA)
		return (cmd_rotate(stack_a));
	if (command == RB)
		return (cmd_rotate(stack_b));
	if (command == RR)
		return (cmd_rr(stack_a, stack_b));
	if (command == RRA)
		return (cmd_reverse(stack_a));
	if (command == RRB)
		return (cmd_reverse(stack_b));
	if (command == RRR)
		return (cmd_rr(stack_a, stack_b));
	return (true);
}
