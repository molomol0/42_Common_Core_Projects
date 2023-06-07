/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:46 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 11:59:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *tmp;

	if (*stack_2 == NULL)
		return ;
	tmp = (*stack_2)->next;
	(*stack_2)->next = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}

// int main(void)
// {
// 	t_stack *list1;
// 	t_stack *list2;
// 	t_stack **head1 = &list1;
// 	t_stack **head2 = &list2;
// 	list1 = ft_lstnew_stack(1);
// 	ft_lstadd_front_stack(&list1, ft_lstnew_stack(1));
// 	ft_lstadd_front_stack(&list1, ft_lstnew_stack(1));
// 	ft_lstadd_front_stack(&list1, ft_lstnew_stack(1));
// 	ft_lstadd_front_stack(&list1, ft_lstnew_stack(1));
// 	list2 = ft_lstnew_stack(2);
// 	ft_lstadd_front_stack(&list2, ft_lstnew_stack(2));
// 	ft_lstadd_front_stack(&list2, ft_lstnew_stack(2));
// 	ft_lstadd_front_stack(&list2, ft_lstnew_stack(2));
// 	ft_lstadd_front_stack(&list2, ft_lstnew_stack(2));
// 	printf("listes de base :\n");
// 	printf("liste 1 : ");
// 	printf_list(list1);
// 	printf("liste 2 : ");
// 	printf_list(list2);
// 	pa(head1, head2);
// 	printf("Listes apres le push:\n");
// 	printf("liste 1 : ");
// 	printf_list(list1);
// 	printf("liste 2 : ");
// 	printf_list(list2);
// }