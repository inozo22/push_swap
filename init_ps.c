/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:08:54 by nimai             #+#    #+#             */
/*   Updated: 2023/02/17 12:00:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//I can use this after sort
//So, before this function, better sort ::>_<::
/* void	check_dub_number(t_pushswap *ps)
{
	long	i;

	i = 0;
	while (i++ < ps->size - 1)
	{
		if (ps->n[i].value == ps->n[i + 1].value)
			exit(ps_error("error, dubbed number '-'"));//Delete comments after adjust
	}
} */

void	check_dub_number(t_pushswap *ps)
{
	long	i;
	long	j;

	i = 1;
	j = 2;
	while (i <= ps->size)
	{
		j = i + 1;
		while (j <= ps->size)
		{
			if (ps->n[i].value == ps->n[j].value)
				exit(ps_error("error, dubbed number '-'"));
			j++;
		}
		i++;
	}
}

/* t_boxes	*make_dummy(void)//ato de kesu
{
	t_boxes	*dummy;

	dummy = malloc(sizeof(t_boxes));
	if (!dummy)
		exit(ps_error("fail allocate dummy"));//It should be freed
	dummy->value = -1;//This value it will not be seen, so it's ok whatever I put
	dummy->next = dummy;
	dummy->prev = dummy;//This is the dummy box, that   
	return (dummy);
} */

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
	while (i++ < ps->size)
	{
		ps->n[i].value = ps_atoi(*strs);
		ps->n[i].id = i;
		strs++;
	}
	check_dub_number(ps);
	i = 0;
	while (i++ < ps->size)
	{
		printf("value\t: %ld\n", ps->n[i].value);
		printf("id %ld\t: %ld\n", i, ps->n[i].id);
	}
	quick_sort(ps->n, 0, ps->size - 1, SORT_VALUE);//2times sort to 1. sort to see the correct position
	//I have to get ID to see where it should go
	//quick_sort(ps->n, 0, ps->size - 1, SORT_ID);//2times sort to 2. to make as an initial
	i = 0;
	while (i++ < ps->size)
	{
		printf("value\t: %ld\n", ps->n[i].value);
		printf("id %ld\t: %ld\n", i, ps->n[i].id);
	}
	return (ps);
}

/* int	main(int ac, char **av)
{
	t_pushswap	*ps;

	ps = init_ps(ac, av);
	printf("ps size: %ld\n", ps->size);
	//list_clear(ps);
} */
