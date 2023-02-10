/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:08:50 by nimai             #+#    #+#             */
/*   Updated: 2023/02/10 14:28:37 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}


int	ps_atoi(char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (is_digit(*str) != 1)
			return (0);//error
		ret = ret * 10 + (*str - 48);
		str++;
	}
	return (ret * sign);
}
