/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:38:49 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/08 17:43:22 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	len;
	long	nl;
	char	*result;

	len = word_count(n);
	nl = n;
	if (n < 0)
		nl *= -1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (nl == 0)
		result[0] = '0';
	else
	{
		while (len--, nl != 0)
		{
			result[len] = (nl % 10) + '0';
			nl = (nl - (nl % 10)) / 10;
		}
		if (n < 0)
			result[len] = '-';
	}
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(9));
// 	printf("%s\n", ft_itoa(-9));
// 	printf("%s\n", ft_itoa(10));
// 	printf("%s\n", ft_itoa(-10));
// 	printf("%s\n", ft_itoa(8124));
// 	printf("%s\n", ft_itoa(-9874));
// 	printf("%s\n", ft_itoa(543000));
// 	printf("%s\n", ft_itoa(-2147483648LL));
// 	printf("%s\n", ft_itoa(2147483647));
// 	return (0);
// }