/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:02:30 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/03 15:19:52 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	int c = -1;
// 	printf("val : %d\n", isalpha(c));
// 	printf("ma val : %d", ft_isalpha(c));
// }
