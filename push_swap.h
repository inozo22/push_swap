/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:26 by nimai             #+#    #+#             */
/*   Updated: 2023/02/13 13:03:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define ARGLIMIT 501

typedef enum e_cmd// to control commands
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_cmd;

typedef struct s_boxes// try to use doubly-circularly-linked list
{
	int				value;//maybe long? to avoid error
	struct s_boxes	*next;
	struct s_boxes	*prev;
}	t_boxes;
// Do not forget put a dummy pointer at the beginning 

/* typedef struct s_pair
{
	int	value;
	int	id;
}	t_pair; */

typedef struct s_pushswap//structure to control in generarl
{
	int			size;
	t_boxes		*answer;
	//t_pair		n[ARGLIMIT];
}	t_pushswap;

typedef struct s_sorting//structure to sort
{
	int	turn;
	int	size;
}	t_sorting;

void	push_swap(int ac, char **av);
int		ps_atoi(char *str);
bool	swap(t_boxes *box);
bool	rotate(t_boxes *box);

#endif
