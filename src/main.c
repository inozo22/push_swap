/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:51 by nimai             #+#    #+#             */
/*   Updated: 2023/02/22 11:18:58 by nimai            ###   ########.fr       */
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
	char	**strs;
	int		len;

	if (ac > ARGLIMIT)
		ps_error("error more than arglimit");
	else if (ac < 2)
		ft_putchar_fd('\n', 1);
	else if (ac == 2)
	{
		strs = ft_split(ft_strjoin(ft_strjoin(av[0], " "), av[1]), 32);
		len = arg_nbr(av[1], 32);
		push_swap(len + 1, strs);
	}
	else if (ac > 2 && ac < 7)//5 numbers
		push_swap(ac, av);
	else
	{
		printf("Think about more than 5 argument later...");
		//push_swap(ac, av);//for test
	}
	return (0);
}
