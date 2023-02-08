/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:49 by nimai             #+#    #+#             */
/*   Updated: 2023/02/07 18:59:42 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	get_list(int ac, char **av)
{
	while (ac == 1)
	{
		

		ac--;
	}

}

void	push_swap(int ac, char **av)
{
	t_stack	stack_a;//stack a, put all av here
	t_stack	stack_b;//stack b, should be empty

	stack_a = malloc(get_list(ac, av));
	
}
