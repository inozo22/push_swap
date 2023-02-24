/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/02/24 17:25:00 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	settle_top(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, t_sorting *sort)
{
	long	i;

	i = -1;
	while ((++i + ps->a) < ps->b)
	{
		if (stack_b->prev->value == ps->b - i - 1)
		{
			cmd_reverse(stack_b);
			sort->tmp[i] = RRB;	
			ps->b++;
		}
		else if (stack_b->prev->prev->value == ps->b - i - 1)
		{
			cmd_reverse(stack_b);
			sort->tmp[i] = RRB;
			ps->b++;
			cmd_reverse(stack_b);
			sort->tmp[i] = RRB;
			ps->b++;
		}
		if (stack_b->next->value == ps->b - i - 1)
		{
			cmd_push(stack_a, stack_b);
			sort->tmp[i] = PA;	
			ps->a++;
		}
	}
	while (stack_a->next->value == ps->a)
	{
		cmd_rotate(stack_a);
		sort->tmp[i] = RA;	
		ps->a++;
	}
}

void	settle_half(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, t_sorting *sort)
{
	long	i;
	long	size_b;
	t_boxes	*tmp_a;

	i = 0;
	size_b = 0;
	tmp_a = stack_a;
	while (i < ps->size && size_b < (ps->size / 2))
	{
		if (tmp_a->next->value < (ps->size / 2))
		{
			cmd_push(stack_b, stack_a);
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


	settle_half(stack_a, stack_b, ps, &sort);//set a half of a to b
	printf("--------------------------------\n");
	printf("■   print stackA and stackB\t■\n■\tafter settle_half\t■\n");
	printf("--------------------------------\n");
	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a->next->value != -1)
	{
		printf("\t%ld\t", tmp_a->next->value);
		if (tmp_b->next->value != -1)
			printf("%ld\t\n", tmp_b->next->value);
		else
			printf("\n");
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	printf("--------------------------------\n");
	printf("■    stackA\tstackB\t\t■\n");
	printf("--------------------------------\n");
	while (ps->a != ps->size)
	{
		settle_top(stack_a, stack_b, ps, &sort);
		return ;

	}
}

/* int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
 */