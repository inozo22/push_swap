/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/02/28 13:40:51 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_a_len(t_boxes *stack_a, t_pushswap *ps)
{
	long	ret;
	long	max;
	t_boxes	*tmp;

	ret = 0;
	max = ARGLIMIT - 10;
	tmp = stack_a->next;
	while ((max - ps->a + 1) != ret && tmp->value)
	{
		ret++;
		if (tmp->value > max)
		{
			max = tmp->value;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	a_qsort(t_boxes *stack_a, t_boxes * stack_b, t_pushswap *ps, long size)
{
	long	i;
	
	i = -1;
	while (++i < size)
	{
		if (stack_b->prev->value == ps->a)
		{
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);	
		}
		if (stack_b->next->next->value == ps->a)
		{
			cmd_swap(stack_b);
			add_box(ps->answer, SB);	
		}
		if (stack_b->next->value == ps->a && (--i || 1))
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);	
		}
		if (stack_a->next->next->value == ps->a && stack_a->next->value == ps->a +1)
		{
			cmd_swap(stack_a);
			add_box(ps->answer, SA);	
		}
		if (stack_a->next->value == ps->a)
		{
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);
			++ps->a;
		}
		else
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);		
		}
	}
}


void	b_qsort(t_boxes *stack_a, t_boxes * stack_b, t_pushswap *ps, long size)
{
	long	i;
	long	pivot;
	long	size_b;
//	long	size_a;
	
	i = -1;
	size_b = size;
//	size_a = 0;
	pivot = ps->a + (size - 1) / 2;
	while (++i < size)
	{
		if (stack_b->next->value == ps->a && size_b-- && ++ps->a)//if the value of next stack_b is same as ps->a, add it to the end of stackA
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);	
//			ps->b++;
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);
//			ps->b++;		
		}
		else if (stack_b->next->value > pivot && size_b--/*  && ++size_a */)//if is grater than pivot, add it to stackA
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);				
		}
		else//neither above, rotate stackB and continue loop
		{
			cmd_rotate(stack_b);
			add_box(ps->answer, RB);
		}
	}
}

long	stack_len(t_boxes *stack)
{
	long	ret;
	t_boxes	*tmp;

	ret = 0;
	tmp = stack;
	while (tmp->next->value != -1)
	{
		ret++;
		tmp = tmp->next;		
	}
	return (ret);	
}

bool	stay_b(t_boxes *stack_b, t_pushswap *ps, long size)
{
	ps->b++;
	if (size == 1)
	{
		printf("stay_b true!\n");
		return (true);		
	}
	if (stack_b->prev->value == ps->b)
		ps->b++;
	cmd_rotate(stack_b);
	add_box(ps->answer, RB);
	printf("stay_b add RB!\n");
	return (false);	
}

void	settle_top(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
	long	i;
	t_boxes *tmp_a;
	t_boxes *tmp_b;

	i = -1;
	printf("ps->b: %ld\n", ps->b);
	while ((++i + ps->a) < ps->b)
	{

		if (stack_b->prev->value == ps->b - i - 1)
		{
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);
//			ps->b++;
		}
		else if (stack_b->prev->prev->value == ps->b - i - 1)
		{
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);
//			ps->b++;
			cmd_reverse(stack_b);
			add_box(ps->answer, RRB);
//			ps->b++;
		}
		if (stack_b->next->value == ps->b - i - 1)
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);
			ps->a++;
		}
	}
	while (stack_a->next->value == ps->a)
	{
		cmd_rotate(stack_a);
		add_box(ps->answer, RA);
		ps->a++;
	}
	printf("--------------------------------\n");
	printf("■   print stackA and stackB\t■\n■\tin settle_top\t■\n");
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
	printf("ps->size: %ld\nps->a: %ld\n", ps->size, ps->a);
//	exit (ps_error("escape\n"));
}

void	settle_half(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)//looks fine this function2023/02/28
{
	long	i;
	long	size_b;
	t_boxes	*tmp_a;
	t_boxes	*tmp_b;

	i = 0;
	size_b = 0;
	tmp_a = stack_a;
 	tmp_b = stack_b;
	while (i < ps->size && size_b < (ps->size / 2))
	{
		while (tmp_b->next->value == ps->b)
		{
			if (stay_b(tmp_b, ps, size_b))
				break;
		}
		if (tmp_a->next->value < (ps->size / 2))
		{
			cmd_push(stack_b, stack_a);
			add_box(ps->answer, PB);
//			sort->tmp[i] = PB;
			size_b++;
		}
		else
		{
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);
//			sort->tmp[i] = RA;
		}
		i++;
		tmp_a = tmp_a->next;
	}
}

void	sort_over5(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
{
//	t_sorting	sort;
	t_boxes	*tmp_a;
	t_boxes	*tmp_b;
	long	size;


	settle_half(stack_a, stack_b, ps);//set a half of a to b
//printer
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

	printf("ps->a: %ld\n", ps->a);
	printf("ps->size: %ld\n", ps->size);
	while (ps->a != ps->size)
	{
//		printf("where am I\n");//here I am! prenty of times...
		settle_top(stack_a, stack_b, ps);
		while ((size = stack_len(stack_b)) > SORT_SIZE)
		{
			printf("where am I? in while qsortB\n");
			b_qsort(stack_a, stack_b, ps, size);
		}
		if (size)
		{
			all_sort(stack_a, stack_b, ps, size);
//			exit (ps_error("in the first allsort: quit here\n"));
		}
		printf("--------------------------------\n");
		printf("■   print stackA and stackB\t■\n■\tafter first_allsort\t■\n");
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
//I have problem with second all_sort, first one looks working well
 		size = get_a_len(stack_a, ps);
		printf("size = %ld\n", size);
//		exit (ps_error("after the first allsort: quit here\n"));
		while ((size = get_a_len(stack_a, ps)) && size <= SORT_SIZE)
		{
			all_sort(stack_a, stack_b, ps, size);
			printf("size: %ld\n", size);
			exit (ps_error("in the second allsort: quit here\n"));
		}
		if (size)
		{
			a_qsort(stack_a, stack_b, ps, size);
		}
//printer to check ps->size and ps->a
		printf("while owariiii   \nps->size: %ld\nps->a: %ld\n", ps->size, ps->a);
	}
	printf("--------------------------------\n");
	printf("■   print stackA and stackB\t■\n■\tafter settle_top\t■\n");
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
}

/* int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}
 */