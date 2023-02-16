/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/02/16 15:45:54 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dub_number(t_boxes *stack_a)
{
	t_boxes	*tmp;
	int	i = 0;
	int j = 0;

	tmp = stack_a;
	while (tmp->next->value != -1)
	{
		while (stack_a->next->value != -1)
		{
			printf("i: %d\nj: %d\ntmp: %ld\nstack_a: %ld\n", i, j, tmp->next->value, stack_a->next->next->value);
			if (tmp->next->value == stack_a->next->next->value)
				exit (ps_error("error, there is dubbed number"));
			stack_a = stack_a->next;
			i++;
		}
		stack_a = stack_a->next;
		tmp = tmp->next;
		j++;
	}
}

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
	/* if (!new)
		return (ps_error());//Here, I have to free the dummy too(clearlist?) */
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
		exit(ps_error("fail allocate dummy"));
	dummy->value = -1;//This value it will not be seen, so it's ok whatever I put
	dummy->next = dummy;
	dummy->prev = dummy;//This is the dummy box, that   
	return (dummy);
}

t_boxes	*put_num(int ac, char **av)
{
	t_boxes	*dummy;
	int		i;

	dummy = make_dummy();
	i = 1;
	while (i < ac)
	{
		add_box(dummy, ps_atoi(av[i]));//is it necessary to check out of int?
		i++;
	}
	return (dummy);
}

void	push_swap(int ac, char **av)
{
	t_boxes	*stack_a;
	t_boxes	*stack_b;
	t_boxes	*ps;

	stack_a = put_num(ac, av);
	check_dub_number(stack_a);
	stack_b = make_dummy();
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
 	printf("------\t------\nstackA\tstackB\n");/*
	search_head(stack_a);
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
	printf("------\t------\nstackA\tstackB\n"); */
}
