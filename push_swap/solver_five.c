/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:56:05 by marvin            #+#    #+#             */
/*   Updated: 2023/06/13 18:56:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_no_push(t_stack **stack_a)
{
	int	index;
	int	coup;

	index = get_pos(stack_a, minimum_stack(stack_a));
	coup = 0;
	if (index <= ((ft_lstsize_stack(*stack_a) + 1) / 2))
	{
		while (index - 1)
		{
			ra(stack_a);
			index--;
			coup++;
		}
	}
	else
	{
		while (ft_lstsize_stack(*stack_a) - index + 1)
		{
			rra(stack_a);
			index++;
			coup++;
		}
	}
	return (coup);
}

void	help(t_stack **stack_a, t_stack **stack_b)
{
	if (max_stack(stack_a) < (*stack_b)->content)
	{
		while ((*stack_b)->content < max_stack(stack_a))
		{
			ra(stack_a);
		}
	}
	else
	{
		while ((*stack_b)->content > (*stack_a)->content)
		{
			ra(stack_a);
		}
	}
}

void	solver_five(t_stack **stack_a)
{
	t_stack	**stack_b;
	int		nb_coup;

	nb_coup = 0;
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
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	solver_three(stack_a);
	help(stack_a, stack_b);
	pa(stack_a, stack_b);
	nb_coup = nb_coup + pop_no_push(stack_a);
	help(stack_a, stack_b);
	pa(stack_a, stack_b);
	nb_coup = nb_coup + pop_no_push(stack_a);
	free_all(stack_b);
}
