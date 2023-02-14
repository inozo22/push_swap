/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:51 by nimai             #+#    #+#             */
/*   Updated: 2023/02/13 13:02:51 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"//add library

int	main(int ac, char **av)
{
	if (ac > ARGLIMIT)
		return (0);//error
	else if (ac < 2)
		ft_putchar_fd('\n', 1);
	else if(ac == 2)
		printf("Think about one argument later...");
	else if(ac > 2 && ac < 7)//5 numbers
		push_swap(ac, av);
	else
	{
		printf("Think about more than 5 argument later...");
		//push_swap(ac, av);//for test
	}
	return (0);
}
