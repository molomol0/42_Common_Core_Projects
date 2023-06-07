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

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	size_t	content;
	struct 	s_stack *next;
	
}	t_stack;

//////////////////////////////////////////////////////////////////////////////////////////////

t_stack	*ft_lstnew_stack(size_t content);
t_stack	*ft_lstlast_stack(t_stack *lst);
int		ft_lstsize_stack(t_stack *lst);
void	ft_lstadd_front_stack(t_stack **lst, t_stack *new);
void 	printf_list(t_stack *list);
int		ft_strcmp(char *s1, char *s2);
void	free_all(t_stack **stack);
t_stack **list_to_stack(char **argv);

#endif