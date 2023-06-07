/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:32:48 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		return (c - 32);
	}
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	int c = 98;
// 	printf("val : %d\n", toupper(c));
// 	printf("ma val : %d", ft_toupper(c));
// }