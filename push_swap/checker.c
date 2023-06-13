/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:14:50 by marvin            #+#    #+#             */
/*   Updated: 2023/06/11 20:14:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void	dup_check_ps(t_stack *head, size_t nbr, t_stack **a)
// {
// 	int i;

// 	i = 0;
// 	while (head)
// 	{
// 		if (head->content == nbr)
// 			i++;
// 		head = head->next;
// 	}
// 	if (i >= 2)
// 	{
// 		ft_putstr_fd("Error\n", 1);
// 		free_all(a);
// 		exit(1);
// 	}
// }

// void	dup_check_c(t_stack *head, size_t nbr, t_stack **a)
// {
// 	int i;

// 	i = 0;
// 	while (head)
// 	{
// 		if (head->content == nbr)
// 			i++;
// 		head = head->next;
// 	}
// 	if (i >= 2)
// 	{
// 		ft_putstr_fd("Error\n", 1);
// 		free_all(a);
// 		exit(1);
// 	}
// }

// void		apply_command(char *str, t_stack **a, t_stack **b)
// {
// 	if (ft_strcmp(str, "sa") == 0)
// 		sa(a);
// 	else if (ft_strcmp(str, "sb") == 0)
// 		sb(b);
// 	else if (ft_strcmp(str, "ss") == 0)
// 		ss(a, b);
// 	else if (ft_strcmp(str, "pa") == 0)
// 		pa(a, b);
// 	else if (ft_strcmp(str, "pb") == 0)
// 		pb(a, b);
// 	else if (ft_strcmp(str, "ra") == 0)
// 		ra(a);
// 	else if (ft_strcmp(str, "rb") == 0)
// 		rb(b);
// 	else if (ft_strcmp(str, "rr") == 0)
// 		rr(a, b);
// 	else if (ft_strcmp(str, "rra") == 0)
// 		rra(a);
// 	else if (ft_strcmp(str, "rrb") == 0)
// 		rrb(b);
// 	else if (ft_strcmp(str, "rrr") == 0)
// 		rrr(a, b);
// 	else
// 		ft_putstr_fd("Error\n", 1);
// }

// int		grab_command(t_stack **a, t_stack **b)
// {
// 	char *line;

// 	line = NULL;
// 	apply_command(line, a, b);
// 	while (get_next_line(&line) > 0)
// 	{
// 		apply_command(line, a, b);
// 		free(line);
// 	}
// 	if (*b != NULL)
// 	{
// 		ft_putstr_fd("\33[31mKO\033[0m\n", 1);
// 		free_all(a);
// 		free_all(b);
// 		exit(1);
// 	}
// 	if (is_sort(a) == 1 && is_sort(b) == 1)
// 		ft_putstr_fd("OK\n", 1);
// 	else
// 		ft_putstr_fd("KO", 1);
// 	return (0);
// }

// t_stack			*create_a_list_c(int argc, char **argv, t_stack **a)
// {
// 	t_stack	*hold_head;
// 	t_stack	*head;
// 	t_stack	*temp;
// 	int		i;

// 	i = 2;
// 	head = malloc(sizeof(t_stack));
// 	hold_head = head;
// 	head->content = ft_atoi(argv[1]);
// 	head->next = NULL;
// 	while (i < argc)
// 	{
// 		temp = malloc(sizeof(t_stack));
// 		temp->content = ft_atoi(argv[i]);
// 		temp->next = NULL;
// 		hold_head->next = temp;
// 		hold_head = hold_head->next;
// 		dup_check_c(head, temp->content, a);
// 		i++;
// 	}
// 	return (head);
// }

// void			print_ok_if_ordered(void)
// {
// 	ft_putstr_fd("OK\n", 1);
// 	exit(1);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	**a;
// 	t_stack	*b;

// 	if (argc < 2)
// 		return (0);
// 	a = create_stack_k(argv);
// 	b = NULL;
// 	if (a == NULL)
// 		return (0);
// 	grab_command(a, &b);
// 	free_all(a);
// 	free_all(&b);
// 	return (0);
// }