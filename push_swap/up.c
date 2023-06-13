/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:55:29 by marvin            #+#    #+#             */
/*   Updated: 2023/06/13 22:55:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertNode(t_stack** head, int content) {
    t_stack* newNode = (t_stack*)malloc(sizeof(t_stack));
    newNode->content = content;
    newNode->next = *head;
    *head = newNode;
}

t_stack *reverseCopy(t_stack *head) {
    t_stack *reversedHead = NULL;
    t_stack *current;
	
	current = head;
    while (current != NULL) {
        insertNode(&reversedHead, current->content);
        current = current->next;
    }
    return (reversedHead);
}

int	get_mini_index(t_stack **stack, size_t key_nbr)
{
	t_stack **reverse_a;
	t_stack	*curr_avant;
	t_stack *curr_arriere;
	int		value;

	value = -1;
	reverse_a = (t_stack **)malloc(sizeof(t_stack *));
	if (!reverse_a)
		return (-1);
	*reverse_a = reverseCopy(*stack);
	curr_avant = *stack;
	curr_arriere = *reverse_a;
	while (curr_avant->content != curr_arriere->content)
	{
		if (curr_avant->content <= key_nbr)
		{
			value = get_pos(stack,curr_avant->content);
			free_all(reverse_a);
			return ( value);
		}
		else if (curr_arriere->content <= key_nbr)
		{
			value = ft_lstsize_stack(*stack) - get_pos(reverse_a, curr_arriere->content) + 1;
			free_all(reverse_a);
			return (value);
		}
		curr_avant = curr_avant->next;
		if (curr_arriere->content != curr_avant->content)
			curr_arriere = curr_arriere->next;
	}
	if(curr_avant->content <= key_nbr)
	{
		value = curr_avant->content;
		free_all(reverse_a);
		return (get_pos(stack, value));
	}
	free_all(reverse_a);
	return (value);
}

void	up(int key_nbr, t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = get_mini_index(stack_a, key_nbr);
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