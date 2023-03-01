/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:51 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 11:34:47 by nimai            ###   ########.fr       */
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
	t_pushswap	ps;

	if (ac > ARGLIMIT)
	{
		ft_putstr_fd("Error\n", STDERR);
/* 		return (ps_error()); */	
	}
	else if (ac < 2)
		ft_putchar_fd('\n', 1);
	else if (ac == 2)
	{
		ps.strs = ft_split(ft_strjoin(ft_strjoin(av[0], " "), av[1]), 32);
		// kokode check?
		ps.len = arg_nbr(av[1], 32);
		push_swap(ps.len + 1, ps.strs);
	}
	else
		push_swap(ac, av);
	return (0);
}
