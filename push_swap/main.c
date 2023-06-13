/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:23:34 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 18:23:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_error(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (duplicate(argv) == 1)
	{
		return (1);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647)
		{
			return (1);
		}
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack **entry;

	if (argc == 1)
	{
		(void)argv;
		return (0);
	}
	if (arg_error(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return 0;
	}
	else
	{
		entry = list_to_stack(argv);
		solver(entry);
		// printf("entry apres : \n");
		// printf_list(*entry);
		// if (is_sort(entry))
		// 	printf("sorted GG");
		// else
		// 	printf("envie de crever");
		free_all(entry);
	}
	return (0);
}
