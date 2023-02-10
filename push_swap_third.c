/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_third.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:49 by nimai             #+#    #+#             */
/*   Updated: 2023/02/10 11:17:00 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*add_num(t_stack *stack_a, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);//error
	new->value = value;//add value to new
	tmp->next = new;//keep next(new)
	tmp->prev = stack_a;//keep prev(stack_a) to tmp
	stack_a->prev = new;//put prev(new) to stack a
	new->prev = tmp;//put prev(tmp<-stacka) to new

	return (stack_a);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);//error
	stack->value = -1;
	stack->next = stack;
	stack->prev = stack;
	return (stack);
}

void	push_swap(int ac, char **av)
{
	t_stack		*stack_a;//stack a, put all av here
	t_stack		*stack_b;//stack b, should be empty
	t_stack		*new;
	t_stack		*tmp;
	t_pushswap	*ps;
	t_stack		head;

	int			i;
	int			len;

	printf("%s", "KOKOmade");
	stack_a = init_stack();
	stack_b = init_stack();
	i = 1;
	len = 0;
	if (ac > 2)
	{
		while (i++ < ac)
		{
			stack_a = add_num(stack_a, (ps->n[len].value = atoi(av[i])));
			len++;
		}
	}

	while (stack_a != NULL)
	{
		printf("%d\t\t\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("------\t------\n");
	printf("A\tB\n");
}
