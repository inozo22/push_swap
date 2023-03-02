/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:53 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 15:57:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	cmd_ss(t_box *stack_a, t_box *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	cmd_swap(stack_a);
	cmd_swap(stack_b);
	return (false);
}

bool	cmd_rr(t_box *stack_a, t_box *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	cmd_rotate(stack_a);
	cmd_rotate(stack_b);
	return (false);
}

bool	cmd_rrr(t_box *stack_a, t_box *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	cmd_reverse(stack_a);
	cmd_reverse(stack_b);
	return (false);
}
