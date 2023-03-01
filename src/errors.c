/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:33:11 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 15:02:10 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


/* void	list_clear(t_boxes *box)
{
	t_boxes	*tmp;

	box->prev->next = NULL;
	while (box)
	{
		tmp = box->next;
		box->prev = NULL;
		free(box);
		box = tmp;
	}
}

void	all_free(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
	list_clear(ps->answer);
	free(ps);
	list_clear(stack_a);
	list_clear(stack_b);
} */

long	ps_error(void)
{
/* 	all_free(stack_a, stack_b, ps); */
	ft_putstr_fd("Error\n", STDERR);
	return (1);
}

long	ps_error1(t_pushswap *ps)
{
	strs_clear(ps->strs, ps->len);
	list_clear(ps->answer);
	free(ps);
	ft_putstr_fd("Error\n", STDERR);
	return (1);
}