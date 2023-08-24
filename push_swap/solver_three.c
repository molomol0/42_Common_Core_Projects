/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:17:14 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 17:17:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver_three(t_stack **stack)
{
	if (is_sort(stack))
		return ;
	if (((*stack)->content > (*stack)->next->content)
		&& ((*stack)->next->content < (*stack)->next->next->content))
	{
		if ((*stack)->content < (*stack)->next->next->content)
			sa(stack);
		else
			ra(stack);
	}
	else if ((*stack)->content < (*stack)->next->content)
	{
		if ((*stack)->content < (*stack)->next->next->content)
		{
			sa(stack);
			ra(stack);
		}
		else
			rra(stack);
	}
	else
	{
		sa(stack);
		rra(stack);
	}
}
