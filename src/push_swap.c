/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:37 by nimai             #+#    #+#             */
/*   Updated: 2023/02/24 13:12:38 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacka(t_boxes *stack)
{
	t_boxes *tmp;

	tmp = stack;
	printf("\n###stack A###\n");
	while (tmp->next->value != -1)
	{
		printf("%ld\n", tmp->next->value);
		tmp = tmp->next;
	}
	printf("###stack A###\n");
}

bool	is_sorted(t_boxes *stack_a)//parece funciona
{
	t_boxes	*tmp;

//	printf("***Im here, in the is sorted***\n");
	tmp = stack_a;
	while (tmp->next->value != -1)
	{
		//printf("CUrrent: %ld Next: %ld\n", tmp->value, tmp->next->value);
		if ((tmp->value) > (tmp->next->value))
		{
//			printf("FALSE!!\n");
			return (false);
		}
		tmp = tmp->next;
	}
	tmp = stack_a;
	printf("\nsorted...\n");
	while (tmp->next->value != -1)
	{
		printf("tmp->value: %ld\n", tmp->next->value);
		tmp = tmp->next;
	}
	return (true);
}

/* t_boxes	*search_head(t_boxes *dummy)//look for the first box that is not a dummy
{
	t_boxes	*ret;

	ret = dummy;
	while (ret->prev->value != -1)
	{
		ret = ret->prev;
	}
	return (ret);
} */

void	add_box(t_boxes *dummy, long num)
{
	t_boxes	*new;
	t_boxes	*tmp;

	new = malloc(sizeof(t_boxes));
	if (!new)
		exit (ps_error("fail allocate new"));//later I have to omid this str
	new->value = num;
	tmp = dummy->prev;
	tmp->next = new;
	new->next = dummy;
	dummy->prev = new;
	new->prev = tmp;
}

t_boxes	*make_dummy(void)
{
	t_boxes	*dummy;

	dummy = malloc(sizeof(t_boxes));
	if (!dummy)
		exit(ps_error("fail allocate dummy"));//It should be freed
	dummy->value = -1;//This value it will compare with dummy value, so its ok with -1
	dummy->next = dummy;
	dummy->prev = dummy;
	return (dummy);
}

t_boxes	*put_num(t_pushswap *ps)
{
	t_boxes	*dummy;
	long	i;

	dummy = make_dummy();
	i = 0;
	while (i < ps->size)
	{
		add_box(dummy, ps->n[i].value);
		i++;
	}
	return (dummy);
}

void	push_swap(int ac, char **av)
{
	t_boxes		*stack_a;
	t_boxes		*stack_b;
	t_pushswap	*ps;
//	long i = 0;

	ps = init_ps(ac, av);
	stack_a = put_num(ps);
	stack_b = make_dummy();
	printf("\nafter the initiation\n");
	print_stacka(stack_a);
	printf("value of stacka next: %ld\n", stack_a->next->value);
	if (stack_a->next->value == -1)
		return (all_free(stack_a, stack_b, ps));
	else if (is_sorted(stack_a))
		printf("is sorted!\n");
	else if (ps->size < 6)
	{
//		printf("enter sort_less6!\n");
		sort_less6(stack_a, stack_b, ps);
	}
	else
	{
		printf("***enter to sort_over5***\n");
		sort_over5(stack_a, stack_b, ps);
	}	
	print_answer(ps->answer);
//	print_stacka(stack_a);
	all_free(stack_a, stack_b, ps);
}

/* int	main(int ac, char **av)
{
	push_swap(ac, av);
}
 */