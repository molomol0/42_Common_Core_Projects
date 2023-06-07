/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:52 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 11:59:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *last;

	tmp = *stack;
	last = ft_lstlast_stack(*stack);
	while(tmp->next != last)
		tmp = tmp->next;
	last->next = *stack;
	*stack = last;
	tmp->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

// int main(void)
// {
// 	t_stack *list;
// 	t_stack **head = &list;
// 	list = ft_lstnew_stack(1); 
// 	ft_lstadd_front_stack(&list, ft_lstnew_stack(2));
// 	ft_lstadd_front_stack(&list, ft_lstnew_stack(3));
// 	ft_lstadd_front_stack(&list, ft_lstnew_stack(4));
// 	ft_lstadd_front_stack(&list, ft_lstnew_stack(5));
// 	printf_list(list);
// 	reverse(head);
// 	printf("Apres le swap :\n");
// 	printf_list(list);
// }