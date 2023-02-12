/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:55:06 by nimai             #+#    #+#             */
/*   Updated: 2023/02/10 11:13:01 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"//add library

int	main(int ac, char **av)
{
	if (ac > ARGLIMIT)
		return (0);//error
	else
		push_swap2(ac, av);//for test
	return (0);
}
