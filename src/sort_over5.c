/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:39:11 by nimai             #+#    #+#             */
/*   Updated: 2023/02/27 10:52:44 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_a_len(t_boxes *stack_a, t_pushswap *ps)
{
	long	ret;
	long	max;
	t_boxes	*tmp;

	ret = 0;
	max = -ARGLIMIT - 10;
	tmp = stack_a->next;
	while (max - ps->a + 1 != ret && tmp->value)
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

void	qsort_a(t_boxes *stack_a, t_boxes * stack_b, t_pushswap *ps, long size)
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


void	qsort_b(t_boxes *stack_a, t_boxes * stack_b, t_pushswap *ps, long size)
{
	long	i;
	long	pivot;
	long	size_b;
	long	size_a;
	
	i = -1;
	size_b = size;
	size_a = 0;
	pivot = ps->a + (size - 1) / 2;
	while (++i < size)
	{
		if (stack_b->next->value == ps->a && size_b-- && ++ps->a)
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);	
//			ps->b++;
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);
//			ps->b++;		
		}
		else if (stack_b->next->value > pivot && size_b-- && ++size_a)
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);				
		}
		else
		{
			cmd_rotate(stack_a);
			add_box(ps->answer, RA);			
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

	i = -1;

	while ((++i + ps->a) < ps->b)
	{
//		printf("Enter settle top\n");
		if (stack_b->prev->value == ps->b - i - 1)
		{
			cmd_reverse(stack_b);
//			sort->tmp[i] = RRB;
			add_box(ps->answer, RRB);
			ps->b++;
		}
		else if (stack_b->prev->prev->value == ps->b - i - 1)
		{
			cmd_reverse(stack_b);
//			sort->tmp[i] = RRB;
			add_box(ps->answer, RRB);
			ps->b++;
			cmd_reverse(stack_b);
//			sort->tmp[i] = RRB;
			add_box(ps->answer, RRB);
			ps->b++;
		}
		if (stack_b->next->value == ps->b - i - 1)
		{
			cmd_push(stack_a, stack_b);
			add_box(ps->answer, PA);
//			sort->tmp[i] = PA;	
			ps->a++;
		}
	}
	while (stack_a->next->value == ps->a)
	{
		cmd_rotate(stack_a);
		add_box(ps->answer, RA);
//		sort->tmp[i] = RA;	
		ps->a++;
	}
}

void	settle_half(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps)
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
		settle_top(stack_a, stack_b, ps);
		while ((size = stack_len(stack_b)) > BSIZE)
		{
			qsort_b(stack_a, stack_b, ps, size);			
		}
		if (size)
		{
			all_sort(stack_a, stack_b, ps, size);
		}
		while ((size = get_a_len(stack_a, ps)) && size <= BSIZE)
		{
			all_sort(stack_a, stack_b, ps, size);			
		}
		if (size)
		{
			qsort_a(stack_a, stack_b, ps, size);
		}
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