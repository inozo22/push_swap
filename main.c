/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:55:06 by nimai             #+#    #+#             */
/*   Updated: 2023/02/06 16:59:28 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"//add library

int	is_num(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	is_int(unsigned int num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	check_error(char *str)
{
	unsigned int	num;
	if (is_num(str) == 1)
	{
		num = ft_atoi(str);
		if (is_int(num) == 1)
		{
			return (num);
		}
		else
			return (0);
	}
	else
	retern (0);//put error 
}

int	main(int ac, char **av)
{
	int				i;
	unsigned int	num;

	i = 1;
	j = 0;
	if (ac >= 2)
	{
		while (av[i])
		{
			num = check_error(av[i]);
			if (num == 0);
				return (0);//error
			else
				push_swap(num);
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}
