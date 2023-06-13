/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:10:56 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 17:10:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_stack **stack_a)
{
	if (is_sort(stack_a) == 0)
	{
		if (ft_lstsize_stack(*stack_a) == 2)
			ra(stack_a);
		else if (ft_lstsize_stack(*stack_a) == 3)
			solver_three(stack_a);
		else if (ft_lstsize_stack(*stack_a) == 5)
			solver_five(stack_a);
		else if (ft_lstsize_stack(*stack_a) <= 10)
			solver_ten(stack_a);
		else if (ft_lstsize_stack(*stack_a) <= 100)
			solver_big(stack_a);
		else
			solver_big_big(stack_a);
	}
}
