/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:49 by nimai             #+#    #+#             */
/*   Updated: 2023/02/10 14:16:52 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*make_dummy(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->value = -1;
	stack->next = stack;
	stack->prev = stack;
	return (stack);
}

void	push_swap(int ac, char **av)
{
	t_stack		*stack_a;//stack a, put all av here
	t_stack		*stack_b;//stack b, should be empty
	t_stack		*start;
	t_stack		*p;
	int			i;
	int			len;

	i = 1;
	len = 0;
	if (ac > 2)
	{
		stack_a = make_dummy();
		stack_b = make_dummy();
		while (i < ac)
		{
			if (i == 1)
			{
				stack_a->next = malloc(sizeof(t_stack));
				start = stack_a;
			}
			else
			{
				stack_a->next = malloc(sizeof(t_stack));
				stack_a = stack_a->next;
			}
			stack_a->value = ps_atoi(av[i]);//make atoi
			stack_a->next = NULL;
			i++;
		}
	}
	stack_a = start;
	while (stack_a != NULL)
	{
		printf("%d\t\t\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("---\t---\n");
	printf("A\tB\n");
}
