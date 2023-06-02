/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:53 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/08 12:46:10 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*p;

	i = 0;
	p = s;
	if (n != 0)
	{
		while (i < n)
		{
			if (p[i] == (char)c)
			{
				return ((void *)&p[i]);
			}
			i++;
		}
	}
	return (NULL);
}
