/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:07:07 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 18:07:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	minimum_stack(t_stack **stack)
{
	size_t	res;
	t_stack *curr;

	res = (*stack)->content;
	curr = *stack;
	while(curr)
	{
		if (curr->content < res)
			res = curr->content;
		curr = curr->next;
	}
	return (res);
}

size_t	max_stack(t_stack **stack)
{
	size_t	res;
	t_stack *curr;

	res = (*stack)->content;
	curr = *stack;
	while(curr)
	{
		if (curr->content > res)
			res = curr->content;
		curr = curr->next;
	}
	return (res);
}

void	pop(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = get_pos(stack_a, minimum_stack(stack_a));
	if (index <= ((ft_lstsize_stack(*stack_a) + 1 ) / 2))
	{
		while (index - 1)
		{
			ra(stack_a);
			index--;
		}
	}
	else
	{
		while (ft_lstsize_stack(*stack_a) - index + 1)
		{
			rra(stack_a);
			index++;
		}
	}
	pb(stack_a, stack_b);
}

void	pop_big(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = get_pos(stack_b, max_stack(stack_b));
	if (index <= ((ft_lstsize_stack(*stack_b) + 1 ) / 2))
	{
		while (index - 1)
		{
			ra(stack_b);
			index--;
		}
	}
	else
	{
		while (ft_lstsize_stack(*stack_b) - index + 1)
		{
			rra(stack_b);
			index++;
		}
	}
	pa(stack_a, stack_b);
}


