/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:26 by nimai             #+#    #+#             */
/*   Updated: 2023/02/21 13:10:38 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define ARGLIMIT 501
# define STDERR 2
# define SORT_ID 0
# define SORT_VALUE 1
# define LIMIT_LESS6 12
# define LIMIT_OVER5 7000//???

typedef enum e_cmd// to control commands
{
	SA,//[0]
	SB,//[1]
	SS,//[2]
	PA,//[3]
	PB,//[4]
	RA,//[5]
	RB,//[6]
	RR,//[7]
	RRA,//[8]
	RRB,//[9]
	RRR,//[10]
}	t_cmd;

typedef struct s_boxes
{
	long			value;
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
	long		init[ARGLIMIT];
}	t_pushswap;

typedef struct s_sorting//structure to sort
{
	long	turn;
	long	size;
	long	tmp[LIMIT_OVER5 + 100];
	long	ans[LIMIT_OVER5 + 100];
	long	max_turn;
	long	pre;

}	t_sorting;

//main functions
void		push_swap(int ac, char **av);
t_pushswap	*init_ps(int ac, char **av);
t_boxes		*make_dummy(void);
void		add_box(t_boxes *dummy, long num);
long		ps_atoi(char *str);
bool		move_stack(t_boxes *stack_a, t_boxes *stack_b, long command, bool ret);
void		print_answer(t_boxes *answer);

//sorting
void		quick_sort(t_pair n[], long left, long right, long flag);
void		sort_less6(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps);
bool		is_sorted(t_boxes *stack_a);

//error control and free
long		ps_error(char *str);//I have to change str to void, for now its ok to check where I got error
void		all_free(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps);
void		list_clear(t_boxes *box);


//commands
bool		cmd_swap(t_boxes *box);
bool		cmd_rotate(t_boxes *box);
bool		cmd_reverse(t_boxes *box);
bool		cmd_push(t_boxes *dst, t_boxes *src);
bool		cmd_ss(t_boxes *stack_a, t_boxes *stack_b);//Verification required
bool		cmd_rr(t_boxes *stack_a, t_boxes *stack_b);//Verification required
bool		cmd_rrr(t_boxes *stack_a, t_boxes *stack_b);//Verification required


#endif
