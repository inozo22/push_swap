/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:33:11 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 18:21:10 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	hollow_error(void)
{
	ft_putstr_fd("Error\n", STDERR);
	return (1);
}

long	ps_error(t_bunch *ps)
{
	if (ps->len)
		strs_clear(ps->strs, ps->len);
	list_clear(ps->answer);
	free(ps);
	ft_putstr_fd("Error\n", STDERR);
	return (1);
}
