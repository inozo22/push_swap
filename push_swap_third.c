/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_third.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:49 by nimai             #+#    #+#             */
/*   Updated: 2023/02/09 19:07:11 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	add_num(t_stack *stack_a, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!(new = malloc(sizeof(t_stack))))
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
	t_stack	*stack_a;

	stack_a->value = -1;
	stack_a->next = stack_a;
	stack_a->prev = stack_a;
	return (stack_a);
}

void	push_swap(int ac, char **av)
{
	t_stack		*stack_a;//stack a, put all av here
	t_stack		*stack_b;//stack b, should be empty
	t_stack		*dummy;
	t_stack		*tmp;
	t_stack		head;

	int			i;
	int			len;

	init_stack();
	i = 1;
	if (ac > 2)
	{
		while (i < ac)
		{
			add_num(stack_a, atoi(av[i]));



		}
		/* stack_a = malloc(sizeof(t_stack));
		stack_a->value = -1;
		dummy = stack_a;
		stack_a->next = NULL;
		stack_a->prev = stack_a;
		while (i < ac)
		{
			stack_a->next = malloc(sizeof(t_stack));
			tmp = stack_a->next;
			stack_a = stack_a->next;
			stack_a->value = atoi(av[i]);
			stack_a->next = NULL;
			stack_a->prev = stack_a;
			i++;
		} */

	}
	stack_a = dummy;
	if (stack_a->value == -1)
		stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		printf("%d\t\t\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("------\t------\n");
	printf("A\tB\n");
}
