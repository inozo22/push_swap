/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:08:54 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 11:48:05 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_dub_number(t_pushswap *ps)
{
	long	i;

	i = 0;
	while (i++ < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit(ps_error1(ps));
	}
}

void	get_id(t_pushswap *ps)
{
	long	i;

	i = 0;
	while (i < ps->size)
	{
		ps->init[i] = ps->n[i].value;
		ps->n[i].value = i;
		i++;
	}
}

/* t_pushswap	*init_ps(int ac, char **av)
{
	t_pushswap	*ps;
	long		i;
	char		**strs;

	ps = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!ps)
		exit(ps_error());
	ps->answer = make_dummy();
	ps->size = ac - 1;
	strs = av + 1;
	i = 0;
	while (i < ps->size)
	{
		ps->n[i].value = ps_atoi(*strs);
		ps->n[i].id = i;
		strs++;
		i++;
	}
	while (i < ARGLIMIT)
	{
		ps->n[i].id = i;
		ps->n[i].value = 0;
		i++;
	}
	ps->a = 0;
	ps->b = 0;
	i = 0;
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);
	check_dub_number(ps);
	get_id(ps);
	quick_sort(ps->n, 0, ps->size - 1, SORT_ID);
	return (ps);
}
 */

t_pushswap	*init_ps(int ac, char **av)
{
	t_pushswap	*ps;
	long		i;
	char		**strs;

	ps = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!ps)
		exit(ps_error());
	ps->answer = make_dummy();
	ps->size = ac - 1;
	strs = av + 1;
	i = 0;
	while (i < ps->size)
	{
		ps->n[i].value = ps_atoi(*strs, ps);
		ps->n[i].id = i;
		strs++;
		i++;
	}
	while (i < ARGLIMIT)
	{
		ps->n[i].id = i;
		ps->n[i].value = 0;
		i++;
	}
	ps->a = 0;
	ps->b = 0;
	i = 0;
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);
	check_dub_number(ps);
	get_id(ps);
	quick_sort(ps->n, 0, ps->size - 1, SORT_ID);
	return (ps);
}
