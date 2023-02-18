/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/02/18 11:25:56 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	is_sorted(t_boxes *stack_a)
{
	while (stack_a->next->value != -1)
	{
		if (!(stack_a->next->value < stack_a->next->next->value))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
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
	dummy->value = -1;//This value it will compare with dummy value
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
		add_box(dummy, ps->n[i].value);
		i++;
	}
	return (dummy);
}

void	push_swap(int ac, char **av)
{
	t_boxes		*stack_a;
	t_boxes		*stack_b;
	t_pushswap	*ps;
	long	sortcheck = 0;
	long i = 0;

	ps = init_ps(ac, av);
	stack_a = put_num(ps);
	stack_b = make_dummy();
	sortcheck = is_sorted(stack_a);
	if (stack_a->next->value == -1)
		return (all_free(stack_a, stack_b, ps));
	else if (sortcheck == 1)
		printf("is sorted!\n");
	else
		printf("You have to sort\n");
	printf("stack_a->next->value: %ld\n", stack_a->next->value);
	while (i < ps->size)
	{
		printf("value[%ld]: %ld\n", i, stack_a->next->value);
		stack_a = stack_a->next;
		i++;
	}

}

int	main(int ac, char **av)
{
	push_swap(ac, av);
}
