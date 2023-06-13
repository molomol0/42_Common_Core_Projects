/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:33:13 by marvin            #+#    #+#             */
/*   Updated: 2023/06/07 18:33:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack **stack)
{
	t_stack	*curr1;
	t_stack	*curr2;

	curr1 = *stack;
	curr2 = (*stack)->next;
	while(curr2)
	{
		if (curr1->content > curr2->content)
			return (0);
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return (1);
}
