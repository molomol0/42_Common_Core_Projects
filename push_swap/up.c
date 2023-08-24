/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/06/13 22:55:29 by marvin            #+#    #+#             */
/*   Updated: 2023/06/13 22:55:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_stack **head, int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->content = content;
	new_node->next = *head;
	*head = new_node;
}

t_stack	*reverse_copy(t_stack *head)
{
	t_stack	*reversed_head;
	t_stack	*current;

	reversed_head = NULL;
	current = head;
	while (current != NULL)
	{
		insert_node(&reversed_head, current->content);
		current = current->next;
	}
	return (reversed_head);
}

int	retu(int value, t_stack **reverse_a)
{
	free_all(reverse_a);
	return (value);
}

int	get_mini_index(t_stack **stack, size_t key_nbr)
{
	t_stack	**reverse_a;
	t_stack	*curr_avant;
	t_stack	*curr_arriere;

	reverse_a = (t_stack **)malloc(sizeof(t_stack *));
	if (!reverse_a)
		return (-1);
	*reverse_a = reverse_copy(*stack);
	curr_avant = *stack;
	curr_arriere = *reverse_a;
	while (curr_avant->content != curr_arriere->content)
	{
		if (curr_avant->content <= key_nbr)
			return (retu(get_pos(stack, curr_avant->content), reverse_a));
		else if (curr_arriere->content <= key_nbr)
			return (retu(ft_lstsize_stack(*stack) - get_pos(reverse_a,
						curr_arriere->content) + 1, reverse_a));
		curr_avant = curr_avant->next;
		if (curr_arriere->content != curr_avant->content)
			curr_arriere = curr_arriere->next;
	}
	if (curr_avant->content <= key_nbr)
		return (retu(get_pos(stack, curr_avant->content), reverse_a));
	return (retu(-1, reverse_a));
}

void	up(int key_nbr, t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	index = get_mini_index(stack_a, key_nbr);
	if (index <= ((ft_lstsize_stack(*stack_a) + 1) / 2))
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
