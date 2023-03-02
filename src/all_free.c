/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:34:34 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 18:21:02 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	list_clear(t_box *box)
{
	t_box	*tmp;

	box->prev->next = NULL;
	while (box)
	{
		tmp = box->next;
		box->prev = NULL;
		free(box);
		box = tmp;
	}
}

char	**strs_clear(char **tab, long i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

void	all_free(t_box *stack_a, t_box *stack_b, t_bunch *ps)
{
	if (ps->len)
		strs_clear(ps->strs, ps->len);
	list_clear(ps->answer);
	free(ps);
	list_clear(stack_a);
	list_clear(stack_b);
}
