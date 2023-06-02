/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:32:45 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/03 15:07:17 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return (c + 32);
	}
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	int c = 81;
// 	printf("val : %d\n", tolower(c));
// 	printf("ma val : %d", ft_tolower(c));
// }