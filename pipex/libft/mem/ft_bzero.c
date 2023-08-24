/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:38 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = s;
	if (str)
	{
		while (i < n)
		{
			str[i] = 0;
			i++;
		}
	}
}

// #include <stdio.h>
// #include <strings.h>
// int main(void)
// {
// 	char s[] = "test";
// 	int t = 4;
// 	bzero(s, t);
// 	printf("val :%s\n", s);
// }