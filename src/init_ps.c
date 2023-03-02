/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:08:54 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 18:21:13 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_digit(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

long	ps_atoi(char *str, t_bunch *ps)
{
	long	ret;
	long	sign;

	ret = 0;
	sign = 1;
	if (ft_strlen(str) > 11)
		exit(ps_error(ps));
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!is_digit(*str))
		exit(ps_error(ps));
	while (is_digit(*str))
	{
		ret = ret * 10 + (*str - 48);
		str++;
	}
	if (*str)
		ps_error(ps);
	ret = ret * sign;
	if (ret < -2147483648 || ret > 2147483647)
		exit(ps_error(ps));
	return (ret);
}

void	check_dub_number(t_bunch *ps)
{
	long	i;

	i = -1;
	while (++i < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit(ps_error(ps));
	}
}

void	get_id(t_bunch *ps)
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

t_bunch	*init_ps(int ac, char **av, t_bunch *ps)
{
	long		i;

	if (!ps->strs)
		ps->strs = av + 1;
	ps->answer = make_dummy();
	ps->size = ac - 1;
	i = -1;
	while (++i < ps->size)
	{
		ps->n[i].value = ps_atoi(ps->strs[i], ps);
		ps->n[i].id = i;
	}
	while (i < ARGLIMIT)
	{
		ps->n[i].id = i;
		ps->n[i].value = 0;
		i++;
	}
	ps->a = 0;
	ps->b = 0;
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);
	check_dub_number(ps);
	get_id(ps);
	quick_sort(ps->n, 0, ps->size - 1, SORT_ID);
	return (ps);
}
