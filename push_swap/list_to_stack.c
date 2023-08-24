/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:19:26 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 19:19:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **stack)
{
	t_stack	*next;

	while (*stack)
	{
		next = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		*stack = next;
	}
	free(stack);
}

t_stack	**list_to_stack(char **argv)
{
	int		i;
	t_stack	**stack;
	t_stack	*curr;

	stack = init();
	curr = *stack;
	i = 1;
	while (argv[i])
	{
		curr->content = ft_atoi(argv[i]);
		if (argv[i + 1])
		{
			curr->next = malloc(sizeof(t_stack));
			if (!curr->next)
			{
				free_all(stack);
				return (NULL);
			}
			curr->next->next = NULL;
			curr = curr->next;
		}
		i++;
	}
	return (stack);
}
