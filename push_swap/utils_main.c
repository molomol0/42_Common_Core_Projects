/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:28:34 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 17:28:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


t_stack	*ft_lstnew_stack(size_t content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlast_stack(t_stack *lst)
{
	if (lst)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

int	ft_lstsize_stack(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstadd_front_stack(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void printf_list(t_stack *list)
{
	while(list != NULL)
	{
		printf("%ld", list->content);
		list = list->next;
		if (list == NULL)
			printf("\n");
		else
			printf("->");
	}
}