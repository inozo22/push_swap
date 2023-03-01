/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 07:11:23 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_boxes *stack_a)
{
	t_boxes	*tmp;

	tmp = stack_a;
	while (tmp->next->value != -1)
	{
		if ((tmp->value) > (tmp->next->value))
		{
			return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}

void	add_box(t_boxes *dummy, long num)
{
	t_boxes	*new;
	t_boxes	*tmp;

	new = malloc(sizeof(t_boxes));
	if (!new)
		exit (ps_error("fail allocate new"));//later I have to omid this str
	new->value = num;
	tmp = dummy->prev;
	tmp->next = new;
	new->next = dummy;
	dummy->prev = new;
	new->prev = tmp;
}

t_boxes	*make_dummy(void)
{
	t_boxes	*dummy;

	dummy = malloc(sizeof(t_boxes));
	if (!dummy)
		exit(ps_error("fail allocate dummy"));
	dummy->value = -1;
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

char	**free_argv(char **av, t_pushswap *ps)
{
	long	i;

	i = 0;
	while (i < ps->size)
	{
		i++;
		free(av[i]);
	}
	free(av);
	return (NULL);
}

void	push_swap(int ac, char **av)
{
	t_boxes		*stack_a;
	t_boxes		*stack_b;
	t_pushswap	*ps;

	ps = init_ps(ac, av);
	stack_a = put_num(ps);
	stack_b = make_dummy();
	if (stack_a->next->value == -1)
	{
		free_argv(av, ps);
		return (all_free(stack_a, stack_b, ps));
	}
	else if (is_sorted(stack_a))
		;
	else if (ps->size < 6)
		sort_less6(stack_a, stack_b, ps);
	else
	{
		sort_over5(stack_a, stack_b, ps);
	}
	print_answer(ps->answer);
	all_free(stack_a, stack_b, ps);
}
