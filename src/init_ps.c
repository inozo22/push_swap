/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:08:54 by nimai             #+#    #+#             */
/*   Updated: 2023/02/28 19:08:02 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_dub_number(t_pushswap *ps)
{
	long	i;

	i = 0;
	while (i++ < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit(ps_error("error, dubbed number '-'"));//Delete comments after adjust
	}
}

void	get_id(t_pushswap *ps)
{
	long	i;

	i = 0;
	while (i < ps->size)
	{
		ps->init[i] = ps->n[i].value;
		ps->n[i].value = i;
		i++;
	}
}

t_pushswap	*init_ps(int ac, char **av)
{
	t_pushswap	*ps;
	long		i;// count you
	char		**strs;

	ps = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!ps)
		exit(ps_error("fail allocate dummy"));//It should be freed
	ps->answer = make_dummy();//to put answer, toriaezu dummy get
	ps->size = ac - 1;
	strs = av + 1;
	i = 0;
	while (i < ps->size)
	{
		ps->n[i].value = ps_atoi(*strs);
		ps->n[i].id = i;
		strs++;
		i++;
	}
	while (i < ARGLIMIT)
	{
		ps->n[i].id = i;
		ps->n[i].value = 0;
		i++;
	}
	ps->a = 0;
	ps->b = 0;
	i = 0;
	printf("initial data\nvalue\tid\t\n-------------\n");
	while (i < ps->size)
	{
		printf("%ld\t%ld\n", ps->n[i].value, ps->n[i].id);
		i++;
	}
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);
	i = 0;
	printf("after 1st qsort\nvalue\tid\t\n-------------\n");
	while (i < ps->size)
	{
		printf("%ld\t%ld\n", ps->n[i].value, ps->n[i].id);
		i++;
	}
	check_dub_number(ps);
	get_id(ps);
	quick_sort(ps->n, 0, ps->size - 1, SORT_ID);
	i = 0;
	printf("after 2nd qsort\nvalue\tid\t\n-------------\n");
	while (i < ps->size)
	{
		printf("%ld\t%ld\n", ps->n[i].value, ps->n[i].id);
		i++;
	}
	return (ps);
}

/* int	main(int ac, char **av)
{
	t_pushswap	*ps;
	long		i;

	i = 0;
	ps = init_ps(ac, av);

	printf("::::::::::\nps size: %ld\n", ps->size);
	printf("This is the list that I have to get\n");
	while (i < ps->size)
	{
		printf("%ld\t\n", ps->init[i]);
		i++;
	}
 	printf("------\t\nstackA\t\n");
	//list_clear(ps);
	return (0);
}
 */