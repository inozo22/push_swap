/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:45:10 by nimai             #+#    #+#             */
/*   Updated: 2023/02/21 13:09:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

void	put_command(long command)
{
	if (command == SA)
		ft_putstr_fd("sa\n", 1);
	if (command == SB)
		ft_putstr_fd("sb\n", 1);	
	if (command == SS)
		ft_putstr_fd("ss\n", 1);
	if (command == RA)
		ft_putstr_fd("ra\n", 1);
	if (command == RB)
		ft_putstr_fd("rb\n", 1);
	if (command == RR)
		ft_putstr_fd("rr\n", 1);
	if (command == RRA)
		ft_putstr_fd("rra\n", 1);	
	if (command == RRB)
		ft_putstr_fd("rrb\n", 1);
	if (command == RRR)
		ft_putstr_fd("rrr\n", 1);
	if (command == PA)
		ft_putstr_fd("pa\n", 1);
	if (command == PB)
		ft_putstr_fd("pb\n", 1);
}

void	print_answer(t_boxes *answer)
{
	t_boxes	*tmp;

	tmp = answer->next;
	while (tmp->value != -1)
	{
		put_command(tmp->value);
		tmp = tmp->next;
	}

}
