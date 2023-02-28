/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:33:11 by nimai             #+#    #+#             */
/*   Updated: 2023/02/28 18:27:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ps_error(char *str)//At the end, I have to change to void, but for now, I put str to see where I give error
{
	ft_putstr_fd(str, STDERR);
	//FREE
	return (1);
}
