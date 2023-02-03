/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.c>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:30:41 by nimai             #+#    #+#             */
/*   Updated: 2022/12/14 11:30:49 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dtemp;
	char		*stemp;
	size_t		i;

	dtemp = (char *)dst;
	stemp = (char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		dtemp[i] = stemp[i];
		i++;
	}
	return (dst);
}
