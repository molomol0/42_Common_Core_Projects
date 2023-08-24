/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_big_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:43:51 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 22:43:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver_big_big(t_stack **stack_a)
{
	t_stack	**stack_k;
	size_t	key_nbr;
	t_stack	**stack_b;
	int		comp;
	int		nb_chunk;

	nb_chunk = 13;
	comp = 1;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	*stack_b = NULL;
	stack_k = create_stack_k(stack_a);
	sort_k(stack_k);
	while (comp != nb_chunk)
	{
		key_nbr = get_from_pos(stack_k, (ft_lstsize_stack(*stack_k) / nb_chunk)
				* comp);
		while (minimum_stack(stack_a) <= key_nbr)
			up(key_nbr, stack_a, stack_b);
		comp++;
	}
	end_solver(stack_a, stack_b);
	free_all(stack_k);
}
