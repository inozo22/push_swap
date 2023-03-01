/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:53 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 07:07:11 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	cmd_ss(t_boxes *stack_a, t_boxes *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	cmd_swap(stack_a);
	cmd_swap(stack_b);
	return (false);
}

bool	cmd_rr(t_boxes *stack_a, t_boxes *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	cmd_rotate(stack_a);
	cmd_rotate(stack_b);
	return (false);
}

bool	cmd_rrr(t_boxes *stack_a, t_boxes *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	cmd_reverse(stack_a);
	cmd_reverse(stack_b);
	return (false);
}
