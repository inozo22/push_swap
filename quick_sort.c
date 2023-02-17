/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:55 by nimai             #+#    #+#             */
/*   Updated: 2023/02/17 13:01:00 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_pairs(t_pair *first, t_pair *second)
{
	long	tmp_id;
	long	tmp_value;

	tmp_id = first->id;
	tmp_value = first->value;
	first->id = second->id;
	first->value = second->value;
	second->id = tmp_id;
	second->value = tmp_value;
}

long	get_pivot_value(t_pair n[], long left, long right)
{
	long	ret;
	long	i;
	long	j;

	i = left;
	j = right + 1;
	ret = left;

	while (i < j)
	{
		while (i < j && n[i].value < n[ret].value)
			i++;
		while (j && n[ret].value > n[j].value)
			j--;
		i++;
	}
	while (i <)



}


void	quick_sort(t_pair n[], long left, long right, long flag)
{
	long	pivot;

	if (left < right)
	{
		if (flag == SORT_VALUE)
		{
			pivot = get_pivot_value(n, left, right);
		}
		if (flag == SORT_ID)
		{
			pivot = get_pivot_id(n, left, right);

		}
		quick_sort(n, left, pivot, flag);
		quick_sort(n, pivot, right, flag);
	}

}
