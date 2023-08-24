/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:05:58 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		deb;
	int		fin;
	int		i;

	deb = 0;
	i = 0;
	fin = ft_strlen(s1);
	while (is_in_set(s1[deb], set) == 1 && s1[deb])
		deb++;
	while (is_in_set(s1[fin - 1], set) == 1 && deb < fin)
		fin--;
	res = malloc((fin - deb + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (deb < fin)
	{
		res[i] = s1[deb];
		deb++;
		i++;
	}
	res[i] = 0;
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char s1[]= "telorem ipsum dolor sit amet";
// 	char s2[]= "et";
// 	printf("%s", ft_strtrim(s1, s2));
// }
