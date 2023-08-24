/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:59 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char srcString[] = "Test string"; 
// 	char destSring[100];
// 	int srcInt[] = {1, 2, 3, 4, 5}; 
// 	int n = sizeof(srcInt)/sizeof(srcInt[0]); 
// 	int destInt[n], i; 
// 	ft_memcpy(destSring, srcString, strlen(srcString)+1); 
// 	printf("String : %s", destSring); 
// 	ft_memcpy(destInt, srcInt, sizeof(srcInt)); 
// 	printf("\nArray : ");
// 	for (i=0; i<n; i++) 
// 		printf("%d ", destInt[i]); 
// 	return 0; 
// } 
