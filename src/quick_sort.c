/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:07:55 by nimai             #+#    #+#             */
/*   Updated: 2023/02/21 14:41:24 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	long	pivot;
	long	i;
	long	j;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (i < j && n[++i].value < n[pivot].value)
			;
		while (j && n[pivot].value < n[--j].value)
			;
		if (i < j)
		{
			swap_pairs(&n[i], &n[j]);
		}
	}
	swap_pairs(&n[pivot], &n[j]);
	return (j);
}

long	get_pivot_id(t_pair n[], long left, long right)//this is a value's copy 
{
	long	pivot;
	long	i;
	long	j;

	i = left;
	j = right + 1;
	pivot = left;
	while (i < j)
	{
		while (n[++i].id < n[pivot].id)
			;
		while (n[pivot].id < n[--j].id)
			;
		if (i < j)
			swap_pairs(&n[i], &n[j]);
	}
	swap_pairs(&n[pivot], &n[j]);
	return (j);
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
		quick_sort(n, left, pivot - 1, flag);
		quick_sort(n, pivot + 1, right, flag);
	}
}
