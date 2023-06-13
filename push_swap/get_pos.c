/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:51:45 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 17:51:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_stack **stack, size_t val)
{
	t_stack	*curr;
	int		index;

	curr = *stack;
	index = 1;
	while (curr)
	{
		if (curr->content == val)
			return (index);
		curr = curr->next;
		index++;
	}
	return (-1);
}

size_t	get_from_pos(t_stack **stack, size_t pos)
{
	t_stack	*curr;

	curr = *stack;
	while (curr && pos - 1)
	{
		curr = curr->next;
		pos--;
	}
	if (!curr)
		return (-1);
	return (curr->content);
}
