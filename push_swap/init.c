/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:07:34 by marvin            #+#    #+#             */
/*   Updated: 2023/06/13 23:07:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**init(void)
{
	t_stack	**stack;

	stack = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack)
		return (NULL);
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack))
	{
		free_all(stack);
		return (NULL);
	}
	return (stack);
}
