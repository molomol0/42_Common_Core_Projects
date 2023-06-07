/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:50 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 11:59:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	ft_lstlast_stack(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
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
// 	rotate(head);
// 	printf("Apres le swap :\n");
// 	printf_list(list);
// }