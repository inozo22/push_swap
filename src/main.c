/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:51 by nimai             #+#    #+#             */
/*   Updated: 2023/05/03 15:13:50 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_nbr(char const *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[x])
	{
		if (str[x] != c)
			i++;
		while (str[x] != c && str[x])
			x++;
		if (str[x])
			x++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_bunch	*ps;

//when there are more than 500 arguments, return ERROR
	if (ac > ARGLIMIT)
	{
		ft_putstr_fd("Error\n", STDERR);
		return (0);
	}
//when there is no arguments, return nothing
	if (ac < 2)
	{
		return (0);
	}
//allocate memory for t_bunch, to control ps->strs
	ps = (t_bunch *)malloc(sizeof(t_bunch));
	if (!ps)
		exit(hollow_error());
//when the argument as a string (or one)
	if (ac == 2)
	{
		ps->strs = ft_split(av[1], 32);
		ps->len = arg_nbr(av[1], 32);
		push_swap(ps->len + 1, ps->strs, ps);
	}
	else
		push_swap(ac, av, ps);
	return (0);
}
