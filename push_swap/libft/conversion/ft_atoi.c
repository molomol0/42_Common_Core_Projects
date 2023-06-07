/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:36 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/06 19:15:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_atoi(const char *nptr)
{
	size_t	res;
	int		signe;
	int		i;

	i = 0;
	res = 0;
	signe = 0;
	while (nptr[i] == 32 || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			signe = 1 - signe;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	if (signe > 0)
		res = res * -1;
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "   	+-123456";
// 	printf("val : %d\n", atoi(s));
// 	printf("ma val : %d\n", ft_atoi(s));
// }