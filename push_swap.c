/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:15:49 by nimai             #+#    #+#             */
/*   Updated: 2023/02/09 12:57:17 by nimai            ###   ########.fr       */
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

t_stack	*ft_lstnew(int value)
{
	t_stack	*stack_a;

	stack_a = malloc(sizeof (t_stack));
	if (!stack_a)
	{
		ft_lstclear(stack_a, void);
		return (NULL);
	}

	stack_a -> value = value;
	stack_a -> next = NULL;
	stack_a -> prev = 	
	return (new_list);
}

void	push_swap(int ac, char **av)
{
	t_stack	*stack_a;//stack a, put all av here
	t_stack	*stack_b;//stack b, should be empty
	int	i;

	//stack_a = malloc(get_list(ac, av));
	i = 0;
	while (*av[i])
		i++;
	stack_a->a_size = i;
	i = 0;
	while (*av[i])
	{

		ft_lstnew(atoi(av[i]));
		stack_a->value = atoi(av[i]);
		i++;
	}
	printf("%d\n", stack_a->value);
}
