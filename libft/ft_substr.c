/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:35:46 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/08 15:25:38 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	res_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		res = ft_calloc(1, sizeof(char));
		if (!res)
			return (NULL);
	}
	else
	{
		res_len = ft_strlen(s + start);
		if (!(res_len < len))
			res_len = len;
		res = (char *)malloc((res_len + 1) * sizeof(char));
		if (!res)
			return (NULL);
		res[res_len] = 0;
		while (res_len-- > 0)
			res[res_len] = s[start + res_len];
	}
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char s[]= "0123456789";
// 	printf("%s", ft_substr(s, 9, 10));
// }