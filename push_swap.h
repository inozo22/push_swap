/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:44:08 by nimai             #+#    #+#             */
/*   Updated: 2023/02/10 11:10:13 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

typedef struct s_stack// try to use doubly-circularly-linked list
{
	int				value;//maybe long? to avoid error
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
// Do not forget put a dummy pointer at the beginning 

typedef struct s_pair
{
	int	value;
	int	id;
}	t_pair;

typedef struct s_pushswap//structure to control in generarl
{
	int			size;
	t_stack		*answer;
	t_pair		n[ARGLIMIT];
}	t_pushswap;




typedef struct s_sorting//structure to sort
{
	int	turn;
	int	size;
}	t_sorting;

void	push_swap(int ac, char **av);

#endif
