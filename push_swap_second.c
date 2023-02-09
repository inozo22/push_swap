/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:49 by nimai             #+#    #+#             */
/*   Updated: 2023/02/09 16:25:19 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap(int ac, char **av)
{
	//t_stack		*stack_a;//stack a, put all av here
	//t_stack		*stack_b;//stack b, should be empty
	t_stack		*start;
	t_stack		*p;
	int			i;
	int			len;

	i = 1;
	len = 0;
	if (ac > 2)
	{
		while (i < ac)
		{
			if (i == 1)
			{
				p = malloc(sizeof(t_stack));
				start = p;
			}
			else
			{
				p->next = malloc(sizeof(t_stack));
				p = p->next;
			}
			p->value = atoi(av[i]);
			p->next = NULL;
			i++;
		}
	}
	p = start;
	while (p != NULL)
	{
		printf("%d\t\t\n", p->value);
		p = p->next;
	}
	printf("---\t---\n");
	printf("A\tB\n");
}
