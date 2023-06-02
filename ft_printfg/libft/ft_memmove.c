/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:32:02 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/16 03:38:25 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest > src)
	{
		i = n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
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
// 	ft_memmove(destSring, srcString, strlen(srcString)+1); 
// 	printf("String : %s", destSring); 
// 	ft_memmove(destInt, srcInt, sizeof(srcInt)); 
// 	printf("\nArray : ");
// 	for (i=0; i<n; i++) 
// 		printf("%d ", destInt[i]);
// 	return 0; 
// } 