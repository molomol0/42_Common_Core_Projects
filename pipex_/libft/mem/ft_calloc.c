/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:41 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/06 12:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*buff;
	size_t	i;

	i = 0;
	if (nitems > sizeof(char) * 2147483424 || size > sizeof(char) * 2147483424)
		return (NULL);
	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	buff = (void *)malloc(nitems * size);
	if (!buff)
		return (NULL);
	while (i < nitems * size)
	{
		((unsigned char *)buff)[i] = 0;
		i++;
	}
	return (buff);
}
