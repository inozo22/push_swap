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
	printf("::::::::::\nprev of dummy before while: %p\n", dummy->prev);
	while (ret->prev != dummy)
	{
		ret = ret->prev;
	}
	printf("point of ret: %p\n", ret);
	return (ret);
}

void	add_box(t_boxes *dummy, int num)
{
	t_boxes	*new;
	t_boxes	*tmp;
	t_boxes	*head;

	printf("********\npoint of dummy before search head: %p\n", dummy);
	head = search_head(dummy);
	new = malloc(sizeof(t_boxes));
	/* if (!new)
		return (ps_error());//Here, I have to free the dummy too(clearlist?) */
	tmp = dummy->prev;
	new->value = num;
	new->next = dummy;
	new->prev = tmp;
	dummy->prev = new;
	dummy->next = head;
	printf("point of head: %p\n", head);
	printf("prev of dummy: %p\nnext of dummy: %p\npoint of dummy: %p\n", dummy->prev, dummy->next, dummy);

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

/* t_boxes	put_num(int ac, char **av)
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

	a = put_num(ac, av);
	b = make_dummy();

} */

void	main(void)
{
	t_boxes *dummy;

	dummy = make_dummy();
	add_box(dummy, 123); 
	add_box(dummy, 234);/*
	add_box(dummy, 345);
	printf("::::::::\nvalue of dummy: %d\npoint of dummy: %p\n", dummy->value, dummy);
	dummy = dummy->prev;
	printf("::::::::\nvalue of dummy: %d\npoint of dummy: %p\n", dummy->value, dummy);
 */
	/* while (dummy->next->value != -1)
	{
		printf("value is %d, pointer is %p\n", dummy->value, dummy);
		dummy = dummy->prev;
	}
 */
}
