/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/02/24 11:41:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	settle_half(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, t_sorting *sort)
{
	long	i;
	long	size_b;
	t_boxes	*tmp_a;

	i = 0;
	size_b = 0;
	tmp_a = stack_a;
	printf("enter settle_half!!\n");
	while (i < ps->size && size_b < (ps->size / 2))
	{
		if (tmp_a->next->value < (ps->size / 2))
		{
			if (cmd_push(stack_b, stack_a))
				printf("false push\n");
			sort->tmp[i] = PB;
			size_b++;

		}
		i++;
		tmp_a = tmp_a->next;
	}
}

void	sort_over5(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
	t_sorting	sort;
	t_boxes	*tmp_a;
	t_boxes	*tmp_b;
	long i = 0;

	
	settle_half(stack_a, stack_b, ps, &sort);//set a half of a to b
/* 	while (ps->a != ps->size)
	{

	} */
	printf("--------------------------------\n");
	printf("■   print stackA and stackB\t■\n■\tafter settle_half\t■\n");
	printf("--------------------------------\n");
	tmp_a = stack_a;
	tmp_b = stack_b;
	while (i < ps->size)
	{
		printf("\t%ld\t", tmp_a->next->value);
		if (tmp_b->next->value != -1)
			printf("%ld\t\n", tmp_b->next->value);
		else
			printf("ops!\n");
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
		i++;
	}
	printf("--------------------------------\n");
	printf("■    stackA\tstackB\t\t■\n");
	printf("--------------------------------\n");
}

int	main(int ac, char **av)
{
	push_swap(ac, av);

	return (0);
}
