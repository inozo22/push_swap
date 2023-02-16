/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:26 by nimai             #+#    #+#             */
/*   Updated: 2023/02/16 17:10:22 by nimai            ###   ########.fr       */
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
# define STDERR 2

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
	long			value;//maybe long? to avoid error
	struct s_boxes	*next;
	struct s_boxes	*prev;
}	t_boxes;
// Do not forget put a dummy pointer at the beginning 

typedef struct s_pair
{
	long	value;
	long	id;
}	t_pair;

typedef struct s_pushswap//structure to control in generarl
{
	long		size;
	t_boxes		*answer;
	t_pair		n[ARGLIMIT];
}	t_pushswap;

typedef struct s_sorting//structure to sort
{
	int	turn;
	int	size;
}	t_sorting;

void		push_swap(int ac, char **av);
t_pushswap	*init_ps(int ac, char **av);
long		ps_error(char *str);//I have to change to void, for now its ok 
void		all_free(t_boxes *stack_a, t_boxes *stack_b);
void		list_clear(t_boxes *box);
long		ps_atoi(char *str);
bool		cmd_swap(t_boxes *box);
bool		cmd_rotate(t_boxes *box);
bool		cmd_reverse(t_boxes *box);
bool		cmd_push(t_boxes *dst, t_boxes *src);
bool		cmd_ss(t_boxes *stack_a, t_boxes *stack_b);//Verification required
bool		cmd_rr(t_boxes *stack_a, t_boxes *stack_b);//Verification required
bool		cmd_rrr(t_boxes *stack_a, t_boxes *stack_b);//Verification required

#endif
