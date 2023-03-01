/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:26 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 15:01:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define STDERR 2
# define ARGLIMIT 501
# define SORT_ID 0
# define SORT_VALUE 1
# define LIMIT_LESS6 12
# define LIMIT_OVER5 30
# define SORT_SIZE 4

typedef enum e_cmd
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

typedef struct s_boxes
{
	long			value;
	struct s_boxes	*next;
	struct s_boxes	*prev;
}	t_boxes;

typedef struct s_pair
{
	long	value;
	long	id;
}	t_pair;

typedef struct s_pushswap
{
	long		size;
	t_boxes		*answer;
	t_pair		n[ARGLIMIT];
	long		init[ARGLIMIT];
	long		a;
	long		b;
	long		ans_ret;
	long		ans_turn;
	char		ans_next[5][10];
	char		**strs;//ato de ikki ni kesu tame
	long		len;
}	t_pushswap;

typedef struct s_sorting
{
	long	turn;
	long	size;
	long	tmp[LIMIT_OVER5 + 10];
	long	ans[LIMIT_OVER5 + 10];
	long	max_turn;
	long	pre;
	long	a;
	long	tail;
}	t_sorting;

//main functions
void		push_swap(int ac, char **av, t_pushswap *ps);
t_pushswap	*init_ps(int ac, char **av, t_pushswap *ps);
t_boxes		*make_dummy(void);
void		add_box(t_boxes *dummy, long num);
/* long		ps_atoi(char *str); */
long		ps_atoi(char *str, t_pushswap *ps);
bool		move_stack(t_boxes *stack_a, t_boxes *stack_b, long cmd, bool ret);
void		print_answer(t_boxes *answer);

//sorting
void		quick_sort(t_pair n[], long left, long right, long flag);
void		sort_less6(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps);
void		sort_over5(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps);
void		dfs_over5(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort, long turn);
void		all_sort(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps, long size);
bool		is_sorted(t_boxes *stack_a);
void		stack_update(t_boxes *stack_a, t_boxes *stack_b, t_sorting *sort);
void		ans_join(t_pushswap *ps, t_sorting *sort);
bool		check_futility(long cmd, t_sorting *sort);
void		add_answer(long turn, t_sorting *sort);

//error control and free
long		ps_error(void);
long		ps_error1(t_pushswap *ps);
//long		ps_error(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps);
void		all_free(t_boxes *stack_a, t_boxes *stack_b, t_pushswap *ps);
void		list_clear(t_boxes *box);
char		**strs_clear(char **tab, long i);

//commands
bool		cmd_swap(t_boxes *box);
bool		cmd_rotate(t_boxes *box);
bool		cmd_reverse(t_boxes *box);
bool		cmd_push(t_boxes *dst, t_boxes *src);
bool		cmd_ss(t_boxes *stack_a, t_boxes *stack_b);
bool		cmd_rr(t_boxes *stack_a, t_boxes *stack_b);
bool		cmd_rrr(t_boxes *stack_a, t_boxes *stack_b);

#endif
