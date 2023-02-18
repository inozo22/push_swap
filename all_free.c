/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:34:34 by nimai             #+#    #+#             */
/*   Updated: 2023/02/18 10:32:38 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_clear(t_boxes *box)
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
	free(ps);
	list_clear(stack_a);
	list_clear(stack_b);
}
