/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:15:22 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 12:15:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct s_stack
{
	size_t			content;
	struct s_stack	*next;
}	t_stack;

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);

t_stack		*ft_lstnew_stack(size_t content);
t_stack		*ft_lstlast_stack(t_stack *lst);
int			ft_lstsize_stack(t_stack *lst);
void		ft_lstadd_front_stack(t_stack **lst, t_stack *new);
void		printf_list(t_stack *list);
int			ft_strcmp(char *s1, char *s2);
void		free_all(t_stack **stack);
t_stack		**list_to_stack(char **argv);
int			is_sort(t_stack **stack);
void		solver(t_stack **stack_a);
void		solver_three(t_stack **stack);
int			get_pos(t_stack **stack, size_t val);
void		pop(t_stack **stack_a, t_stack **stack_b);
void		solver_ten(t_stack **stack_a);
t_stack		**create_stack_k(t_stack **stack_a);
void		sort_k(t_stack **stack);
size_t		get_from_pos(t_stack **stack, size_t pos);
size_t		minimum_stack(t_stack **stack);
size_t		max_stack(t_stack **stack);
void		solver_big(t_stack **stack_a);
void		pop_big(t_stack **stack_a, t_stack **stack_b);
void		solver_big_big(t_stack **stack_a);
void		up(int key_nbr, t_stack **stack_a, t_stack **stack_b);
int			get_mini_index(t_stack **stack, size_t key_nbr);
void		solver_five(t_stack **stack);
t_stack		**init(void);
void		end_solver(t_stack **stack_a, t_stack **stack_b);

#endif