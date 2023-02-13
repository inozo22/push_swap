/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/02/13 13:02:37 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boxes	make_stack(void)
{
	t_boxes	*new;

	new = malloc(sizeof(t_boxes));
	if (!new)
		return (ps_error());
}

t_boxes	put_num(int ac, char **av)
{
	t_boxes	*ret;

	ret = make_stack();


}

void	push_swap(int ac, char **av)
{
	t_boxes	*a[4];
	t_boxes	*b[];

	a = put_num(ac, av);
	b = make_stack();




}
