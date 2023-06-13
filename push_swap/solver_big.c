/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:12 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 16:56:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack **create_stack_k(t_stack **stack_a)
{
    t_stack**	stack_k;
    t_stack*	curr_a;
    t_stack*	curr_k;

	// stack_k = malloc(sizeof(t_stack*));
	// if (!stack_k)
	// 	return (NULL);
	// *stack_k = (t_stack *)malloc(sizeof(t_stack));
	// if (!(*stack_k))
	// {
	// 	free_all(stack_k);
	// 	return (NULL);
	// }
	stack_k = init();
	curr_a = *stack_a;
	curr_k = *stack_k;
    while (curr_a != NULL)
	{
		curr_k->content = curr_a->content;
		if (curr_a->next != NULL)
		{
			curr_k->next = malloc(sizeof(t_stack));
			if (!curr_k->next)
			{
				free_all(stack_k);
				return (NULL);
			}
			curr_k->next->next = NULL;
			curr_k = curr_k->next;
		}
		curr_a = curr_a->next;
    }
    return stack_k;
}

void inserer(t_stack** stack, t_stack* nouveauNoeud) 
{
    t_stack* courant;

	courant = *stack;
    if (*stack == NULL || (*stack)->content >= nouveauNoeud->content)
	{
        nouveauNoeud->next = *stack;
        *stack = nouveauNoeud;
    } 
	else 
	{
        while (courant->next != NULL && courant->next->content < nouveauNoeud->content) {
            courant = courant->next;
        }
        nouveauNoeud->next = courant->next;
        courant->next = nouveauNoeud;
    }
}

void sort_k(t_stack** stack)
{
	t_stack* listeTriee = NULL;
    t_stack* courant = *stack;
	t_stack* next;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    while (courant != NULL)
	{
        next = courant->next;
        inserer(&listeTriee, courant);
        courant = next;
    }
    *stack = listeTriee;
}

void	solver_big(t_stack **stack_a)
{
	t_stack	**stack_k;
	size_t key_nbr;
	t_stack **stack_b;
	int		comp;
	int		nb_chunk;

	nb_chunk = 5;
	comp = 1;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_b)
		return ;
	// *stack_b = (t_stack *)malloc(sizeof(t_stack));
	// if (!(*stack_b))
	// {
	// 	free_all(stack_b);
	// 	return ;
	// }
	*stack_b = NULL;
	stack_k = create_stack_k(stack_a);
	sort_k(stack_k);
	while (comp != nb_chunk)
	{
		key_nbr = get_from_pos(stack_k, (ft_lstsize_stack(*stack_k) / nb_chunk) * comp);
		while (minimum_stack(stack_a) <= key_nbr)
			up(key_nbr, stack_a, stack_b);
		comp++;
	}
	while (*stack_a != NULL)
		pop(stack_a, stack_b);
	while (*stack_b != NULL)
		pop_big(stack_a, stack_b);
	free_all(stack_b);
	free_all(stack_k);
}
