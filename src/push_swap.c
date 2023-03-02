/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 18:21:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_box *stack_a)
{
	t_box	*tmp;

	tmp = stack_a;
	while (tmp->next->value != -1)
	{
		if ((tmp->value) > (tmp->next->value))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	add_box(t_box *dummy, long num)
{
	t_box	*new;
	t_box	*tmp;

	new = malloc(sizeof(t_box));
	if (!new)
		exit (hollow_error());
	new->value = num;
	tmp = dummy->prev;
	tmp->next = new;
	new->next = dummy;
	dummy->prev = new;
	new->prev = tmp;
}

t_box	*make_dummy(void)
{
	t_box	*dummy;

	dummy = malloc(sizeof(t_box));
	if (!dummy)
		exit(hollow_error());
	dummy->value = -1;
	dummy->next = dummy;
	dummy->prev = dummy;
	return (dummy);
}

t_box	*put_num(t_bunch *ps)
{
	t_box	*dummy;
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

void	push_swap(int ac, char **av, t_bunch *ps)
{
	t_box		*stack_a;
	t_box		*stack_b;

	ps = init_ps(ac, av, ps);
	stack_a = put_num(ps);
	stack_b = make_dummy();
	if (stack_a->next->value == -1)
		return (all_free(stack_a, stack_b, ps));
	else if (is_sorted(stack_a))
		;
	else if (ps->size < 6)
		sort_less6(stack_a, stack_b, ps);
	else
		sort_over5(stack_a, stack_b, ps);
	combine_cmd(ps->answer);
	print_answer(ps->answer);
	all_free(stack_a, stack_b, ps);
}
