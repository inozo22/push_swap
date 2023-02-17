/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/02/17 15:02:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boxes	*search_head(t_boxes *dummy)//look for the first box that is not a dummy
{
	t_boxes	*ret;

	ret = dummy;
	while (ret->prev->value != -1)
	{
		ret = ret->prev;
	}
	return (ret);
}

void	add_box(t_boxes *dummy, long num)
{
	t_boxes	*new;
	t_boxes	*tmp;
	t_boxes	*head;

	head = search_head(dummy);
	new = malloc(sizeof(t_boxes));
	if (!new)
		exit (ps_error("fail allocate new"));//later I have to omid this str
	tmp = dummy->prev;
	tmp->next = new;//
	new->value = num;
	new->next = dummy;
	new->prev = tmp;
	dummy->prev = new;
	dummy->next = head;
}

t_boxes	*make_dummy(void)
{
	t_boxes	*dummy;

	dummy = malloc(sizeof(t_boxes));
	if (!dummy)
		exit(ps_error("fail allocate dummy"));//It should be freed
	dummy->value = -1;//This value it will not be seen, so it's ok whatever I put
	dummy->next = dummy;
	dummy->prev = dummy;
	return (dummy);
}

t_boxes	*put_num(t_pushswap *ps)
{
	t_boxes	*dummy;
	long	i;

	dummy = make_dummy();
	i = 0;
	while (i < ps->size)
	{
		add_box(dummy, ps->n[i].value);//is it necessary to check out of int?
		i++;
	}
	return (dummy);
}

void	push_swap(int ac, char **av)
{
	t_boxes		*stack_a;
	t_boxes		*stack_b;
	t_pushswap	*ps;

	ps = init_ps(ac, av);
	stack_a = put_num(ps);
	stack_b = make_dummy();
	/* while (stack_a->next->value != -1)
	{
		printf("%ld\t", stack_a->next->value);
		if (stack_b->next->value != -1)
			printf("%ld\n", stack_b->next->value);
		else
			printf(" \n");
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
 	printf("------\t------\nstackA\tstackB\n"); */
/* 	search_head(stack_a);
	stack_a = stack_a->prev;
	printf("+++++++\nstakca value: %ld\nstacka pointer: %p\n\n", stack_a->value, stack_a);
	while (stack_a->value != -1)
		stack_a = stack_a->next;
	printf("+++++++\nhead value: %ld\nhead pointer: %p\n\n", stack_a->value, stack_a);
	cmd_push(stack_b, stack_a);
	printf("@@@@@@\nvalue of stacka: %ld\n", stack_a->value);
	while (stack_a->next->value != -1)
	{
		printf("%ld\t", stack_a->next->value);
		if (stack_b->next->value != -1)
			printf("%ld\n", stack_b->next->value);
		else
			printf(" \n");
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	printf("------\t------\nstackA\tstackB\n");
	all_free(stack_a, stack_b);
	printf("\n:::::::::excuted all_free:::::::::\n");
	while (stack_a->next->value != -1)
	{
		printf("%ld\t", stack_a->next->value);
		if (stack_b->next->value != -1)
			printf("%ld\n", stack_b->next->value);
		else
			printf(" \n");
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	printf("------\t------\nstackA\tstackB\n");  */
}
