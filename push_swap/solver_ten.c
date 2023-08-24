/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_ten.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:50:37 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 17:50:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver_ten(t_stack **stack_a)
{
	t_stack	**stack_b;

	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	*stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack_b))
	{
		free_all(stack_b);
		return ;
	}
	(*stack_b)->next = NULL;
	while (*stack_a != NULL)
		pop(stack_a, stack_b);
	while ((*stack_b)->next)
		pa(stack_a, stack_b);
	free_all(stack_b);
}
