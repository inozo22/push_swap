/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:51 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 15:21:33 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	t_pushswap	*ps;

	if (ac > ARGLIMIT)
	{
		ft_putstr_fd("Error\n", STDERR);
		return (0);
	}
	if (ac < 2)
	{
		return (0);
		ft_putchar_fd('\n', 1);		
	}
	ps = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!ps)
		exit(ps_error());
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
