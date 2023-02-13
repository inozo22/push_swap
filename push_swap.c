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

t_boxes	*search_head(t_boxes *dummy)//I think I should eliminate this
{//think about it later
	t_boxes	*ret;

	ret = dummy;
	while (ret->next != dummy)
	{
		ret = ret->next;
	}
	printf("point of ret: %p\n", ret->prev);
	return (ret);
}

void	add_box(t_boxes *dummy, int num)
{
	t_boxes	*new;
	t_boxes	*tmp;
	t_boxes	*head;

	head = search_head(dummy);
	new = malloc(sizeof(t_boxes));
	/* if (!new)
		return (ps_error());//Here, I have to free the dummy too(clearlist?) */
	tmp = dummy->prev;
	//printf("point of dummy's prev: %p\npoint of dummy: %p\n", dummy->prev, dummy);
	new->value = num;
	new->next = dummy;
	new->prev = tmp;
	dummy->prev = new;
	dummy->next = head;
	printf("point of head: %p\n", head);
	printf("prev of dummy: %p\nnext of dummy: %p\npoint of dummy: %p\n", dummy->prev, dummy->next, dummy);
	//printf("value of new: %d\npoint of new: %p\nnext of new: %p\nprev of new: %p\n",\
	 new->value, new, new->next, new->prev);
	//printf("point of dummy's prev: %p\npoint of dummy's next: %p\npoint of dummy: %p\n", dummy->prev, dummy->next, dummy);
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
	//printf("value of dummy: %d\npoint of dummy: %p\nnext of dummy: %p\nprev of dummy: %p\n",\
	 dummy->value, dummy, dummy->next, dummy->prev);
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
	add_box(dummy, 123);/* 
	add_box(dummy, 234);
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
