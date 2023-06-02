/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:56 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/16 03:38:25 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*a;
	const char	*b;

	i = 0;
	a = s1;
	b = s2;
	while (i < n)
	{
		if (a[i] == b[i])
			i++;
		else
			return ((unsigned char)a[i] - (unsigned char)b[i]);
	}
	return (0);
}
