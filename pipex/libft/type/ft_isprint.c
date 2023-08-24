/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:50 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
	}
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	int c = 26;
// 	printf("val : %d\n", isprint(c));
// 	printf("ma val : %d", ft_isprint(c));
// }