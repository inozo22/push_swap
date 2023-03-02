/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:26 by nimai             #+#    #+#             */
/*   Updated: 2023/03/02 16:52:12 by nimai            ###   ########.fr       */
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

typedef struct s_box
{
	long			value;
	struct s_box	*next;
	struct s_box	*prev;
}	t_box;

typedef struct s_pair
{
	long	value;
	long	id;
}	t_pair;

typedef struct s_pushswap
{
	long		size;
	t_box		*answer;
	t_pair		n[ARGLIMIT];
	long		init[ARGLIMIT];
	long		a;
	long		b;
	long		ans_ret;
	long		ans_turn;
	char		ans_next[5][10];
	char		**strs;
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
t_box		*make_dummy(void);
void		add_box(t_box *dummy, long num);
long		ps_atoi(char *str, t_pushswap *ps);
void		print_answer(t_box *answer);
int			is_digit(char c);

//sorting
void		quick_sort(t_pair n[], long left, long right, long flag);
void		sort_less6(t_box *stack_a, t_box *stack_b, t_pushswap *ps);
void		sort_over5(t_box *stack_a, t_box *stack_b, t_pushswap *ps);
void		dfs_over5(t_box *stack_a, t_box *stack_b, t_sorting *sort, long t);
void		all_sort(t_box *stack_a, t_box *stack_b, t_pushswap *ps, long size);
bool		is_sorted(t_box *stack_a);
bool		move_stack(t_box *stack_a, t_box *stack_b, long cmd, bool ret);
void		move_add_box(t_box *stack_a, t_box *stack_b, t_pushswap *ps, long cmd);
void		combine_cmd(t_box *answer);
void		converge_box(t_box *answer, long cmd);
void		stack_update(t_box *stack_a, t_box *stack_b, t_sorting *sort);
void		ans_join(t_pushswap *ps, t_sorting *sort);
bool		check_futility(long cmd, t_sorting *sort);
void		add_answer(long turn, t_sorting *sort);
//sort over5
bool		b_left(t_box *stack_b, t_pushswap *ps);
void		a_qsort(t_box *stack_a, t_box *stack_b, t_pushswap *ps, long size);
void		b_qsort(t_box *stack_a, t_box *stack_b, t_pushswap *ps, long size);
long		stack_len(t_box *stack);
bool		disturb_check(t_box *stack_a, long cmd, t_sorting *sort);

//error control and free
long		hollow_error(void);
long		ps_error(t_pushswap *ps);
//long		ps_error(t_box *stack_a, t_box *stack_b, t_pushswap *ps);
void		all_free(t_box *stack_a, t_box *stack_b, t_pushswap *ps);
void		list_clear(t_box *box);
char		**strs_clear(char **tab, long i);

//commands
bool		cmd_swap(t_box *box);
bool		cmd_rotate(t_box *box);
bool		cmd_reverse(t_box *box);
bool		cmd_push(t_box *dst, t_box *src);
bool		cmd_ss(t_box *stack_a, t_box *stack_b);
bool		cmd_rr(t_box *stack_a, t_box *stack_b);
bool		cmd_rrr(t_box *stack_a, t_box *stack_b);

#endif
