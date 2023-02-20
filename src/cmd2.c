/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:53 by nimai             #+#    #+#             */
/*   Updated: 2023/02/20 13:07:00 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	cmd_ss(t_boxes *stack_a, t_boxes *stack_b)
{
	bool	ret;

	ret = false;
	ret |= cmd_swap(stack_a);
	ret |= cmd_swap(stack_b);
	return (ret);
}

bool	cmd_rr(t_boxes *stack_a, t_boxes *stack_b)
{
	bool	ret;

	ret = false;
	ret |= cmd_rotate(stack_a);
	ret |= cmd_rotate(stack_b);
	return (ret);
}

bool	cmd_rrr(t_boxes *stack_a, t_boxes *stack_b)
{
	bool	ret;

	ret = false;
	ret |= cmd_reverse(stack_a);
	ret |= cmd_reverse(stack_b);
	return (ret);
}
