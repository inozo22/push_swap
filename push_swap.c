/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/02/13 13:02:37 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boxes	*search_head(t_boxes *dummy)
{
	t_boxes	*ret;

	ret = dummy;
	while (ret->prev != dummy)
	{
		ret = ret->prev;
	}
	return (ret);
}

void	add_box(t_boxes *dummy, int num)
{
	t_boxes	*new;
	t_boxes	*tmp;
	t_boxes	*head;

	//printf(":::\npoint of dummy: %p\nnext of dummy: %p\nprev of dummy: %p\n", dummy, dummy->next, dummy->prev);
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
	/* if (!dummy)
		return (ps_error()); */
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

	stack_a = put_num(ac, av);
	stack_b = make_dummy();
	/* printf(":::::\nvalue of stacka: %d\npoint of stacka: %p\n", stack_a->value, stack_a);
	printf("\n:::::\nnext value of stacka: %d\npoint of stacka: %p\n", stack_a->next->value, stack_a);
	printf("\n:::::\nnext next value of stacka: %d\npoint of stacka: %p\n", stack_a->next->next->value, stack_a); */
	/* while (stack_a->next->value != -1)
	{
		printf("%d\t%d\n", stack_a->next->value, stack_b->next->value);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	printf("------\t------\nstackA\tstackB\n"); */
	swap(stack_a);
	printf("@@@@@@\nvalue of stacka: %d\n", stack_a->value);
	while (stack_a->next->value != -1)
	{
		printf("%d\t%d\n", stack_a->next->value, stack_b->next->value);
		stack_a = stack_a->next;
		stack_b = stack_b->next;
	}
	printf("------\t------\nstackA\tstackB\n");
	printf("'-' '-' '-'\nnext of stacka: %p\nprev of stacka:%p\npoint of stacka: %p\n", stack_a->next, stack_a->prev, stack_a);
	printf("'-' '-' '-'\nvalue next of stacka: %d\nvalue prev of stacka:%d\nvalue of stacka: %d\n", stack_a->next->value, stack_a->prev->value, stack_a->value);

}

/* void	main(void)
{
	t_boxes *dummy;

	dummy = make_dummy();
	add_box(dummy, 123); 
	printf(":::::::::\npoint of dummy: %p\nvalue of dummy->prev: %d\nvalue of dummy->next: %d\n", dummy, dummy->prev->value, dummy->next->value);
	add_box(dummy, 234);
	printf(":::::::::\npoint of dummy: %p\nvalue of dummy->prev: %d\nvalue of dummy->next: %d\n", dummy, dummy->prev->value, dummy->next->value);
	add_box(dummy, 345);
	printf(":::::::::\npoint of dummy: %p\nvalue of dummy->prev: %d\nvalue of dummy->next: %d\n", dummy, dummy->prev->value, dummy->next->value);
	printf("::::::::\n%d\t \n%d\t \n%d\t \n----\t----\na\tb", dummy->prev->value, dummy->prev->prev->value, dummy->prev->prev->prev->value);
/*
	printf("::::::::\nvalue of dummy: %d\npoint of dummy: %p\n", dummy->value, dummy);
	dummy = dummy->prev;
	printf("::::::::\nvalue of dummy: %d\npoint of dummy: %p\n", dummy->value, dummy);
 
	/* while (dummy->next->value != -1)
	{
		printf("value is %d, pointer is %p\n", dummy->value, dummy);
		dummy = dummy->prev;
	}
 
} */
