/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:09 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 11:49:25 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_digit(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

long	ps_atoi(char *str, t_pushswap *ps)
{
	long	ret;
	long	sign;

	ret = 0;
	sign = 1;
	if (ft_strlen(str) > 11)
		exit(ps_error1(ps));
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (is_digit(*str) != 1)
			exit(ps_error1(ps));
		ret = ret * 10 + (*str - 48);
		str++;
	}
	if (ret < -2147483648 || ret > 2147483647)
		exit(ps_error1(ps));
	return (ret * sign);
}
