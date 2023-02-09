/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:49 by nimai             #+#    #+#             */
/*   Updated: 2023/02/09 16:25:20 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* t_stack	get_list(int ac, char **av)
{
	while (ac == 1)
	{
		

		ac--;
	}

} */

int	ft_lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	while (*lst)
		lst = &((*lst)->next);
	*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}



t_stack	*add_lst(int value, t_pushswap *pushswap)
{
	t_stack	*new;
	t_stack	*tmp;
	int		i;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);//error, liberar
	new->value = -1;
	new->next = new;
	new->prev = new;
	i = 0;
	while (i < pushswap->a_size)
	{
		
	}





	if (stack_a->value == -1)
	{
		if (!(new = (t_stack *)malloc(sizeof(t_stack))))
			return (0);//error, liberar
		tmp = stack_a->next;
		new = 
	}



	stack_a = malloc(sizeof (t_stack));
	if (!stack_a)
	{
		ft_lstclear(stack_a, void);
		return (NULL);
	}

	stack_a->value = value;
	stack_a->next = NULL;
	stack_a->prev = 	
	return (new_list);
}


void	push_swap(int ac, char **av)
{
	t_stack		*stack_a;//stack a, put all av here
	t_stack		*stack_b;//stack b, should be empty
	t_pushswap	*pushswap;
	int	i;

	i = 0;
	init_pushswap(pushswap);//initialize the structure a_size = 0, n = 0, ps_error = 0; 
	while (*av[i])
		i++;
	pushswap->a_size = i;
	i = 0;
	while (*av[i])
	{
		add_list(atoi(av[i]), *pushswap);

		//ft_lstnew(atoi(av[i]));
		stack_a->value = atoi(av[i]);
		i++;
	}
	printf("%d\n", stack_a->value);
}
