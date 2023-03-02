/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 09:56:01 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	converge_box(t_boxes *answer, long cmd)
{
	t_boxes	*tmp;

	tmp = answer->next->next;
	free(answer->next);
	answer->next = NULL;
	answer->value = cmd;
	answer->next = tmp;
	tmp->prev = answer;
}

void	combine_cmd(t_boxes *answer)
{
	t_boxes	*tmp;

	tmp = answer->next;
	while (tmp->value != -1)
	{
		if (tmp->value == RA && tmp->next->value == RB)
			converge_box(tmp, RR);
		if (tmp->value == RB && tmp->next->value == RA)
			converge_box(tmp, RR);
		if (tmp->value == SA && tmp->next->value == SB)
			converge_box(tmp, SS);
		if (tmp->value == SB && tmp->next->value == SA)
			converge_box(tmp, SS);
		if (tmp->value == RRA && tmp->next->value == RRB)
			converge_box(tmp, RRR);
		if (tmp->value == RRB && tmp->next->value == RRA)
			converge_box(tmp, RRR);
		tmp = tmp->next;
	}	
}

bool	is_sorted(t_boxes *stack_a)
{
	t_boxes	*tmp;

	tmp = stack_a;
	while (tmp->next->value != -1)
	{
		if ((tmp->value) > (tmp->next->value))
			return (false);
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
		exit (ps_error());
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
		exit(ps_error());
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

void	push_swap(int ac, char **av, t_pushswap *ps)
{
	t_boxes		*stack_a;
	t_boxes		*stack_b;

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
