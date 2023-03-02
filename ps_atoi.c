/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:09 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 16:06:28 by nimai            ###   ########.fr       */
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
	if (ret < -2147483648 || ret > 2147483647)
		exit(ps_error(ps));
	return (ret * sign);
}
