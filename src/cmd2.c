/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:53 by nimai             #+#    #+#             */
/*   Updated: 2023/02/27 16:11:38 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	cmd_ss(t_boxes *stack_a, t_boxes *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	printf("\nCMD-SS\n");
	cmd_swap(stack_a);
	cmd_swap(stack_b);
	return (false);
//	return (stack_b->next->next->value == -1 || cmd_swap(stack_a) || cmd_swap(stack_b));
/* 	bool	ret;

	ret = false;
	ret |= cmd_swap(stack_a);
	ret |= cmd_swap(stack_b);
	return (ret); */
}

bool	cmd_rr(t_boxes *stack_a, t_boxes *stack_b)
{
	if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);
	printf("\nCMD-RR\n");
	cmd_rotate(stack_a);
	cmd_rotate(stack_b);
	return (false);
//	return (stack_b->next->next->value == -1 || cmd_rotate(stack_a) || cmd_rotate(stack_b));
/* 	bool	ret;

	ret = false;
	ret |= cmd_rotate(stack_a);
	ret |= cmd_rotate(stack_b);
	return (ret); */
}

bool	cmd_rrr(t_boxes *stack_a, t_boxes *stack_b)
{
	/* if (stack_b->next->next->value == -1)
		return (true);
	if (stack_a->next->next->value == -1)
		return (true);

	cmd_reverse(stack_a);
	cmd_reverse(stack_b);
	return (false); */
	printf("\nCMD-RRR\n");
	return (stack_b->next->next->value == -1 || cmd_reverse(stack_a) || cmd_reverse(stack_b));
/* 	bool	ret;

	ret = false;
	ret |= cmd_reverse(stack_a);
	ret |= cmd_reverse(stack_b);
	return (ret); */
}
