/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:55 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 11:59:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	size_t tmp;

	if (*stack == NULL)
		return ;
	tmp = (*stack)->next->content;
	(*stack)->next->content = (*stack)->content;
	(*stack)->content = tmp;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

// int main(void)
// {
// 	t_stack *list;
// 	t_stack **head = &list;
// 	list = ft_lstnew_stack(1); 
// 	ft_lstadd_front_stack(&list, ft_lstnew_stack(2));
// 	printf_list(list);
// 	sa(head);
// 	printf("Apres le swap :\n");
// 	printf_list(list);
// }