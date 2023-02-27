/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:34:31 by nimai             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/23 21:28:22 by nimai            ###   ########.fr       */
=======
/*   Updated: 2023/02/25 12:40:02 by nimai            ###   ########.fr       */
>>>>>>> branch0224
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s) + 1;
<<<<<<< HEAD
 	i = 0;
=======
	i = 0;
>>>>>>> branch0224
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
