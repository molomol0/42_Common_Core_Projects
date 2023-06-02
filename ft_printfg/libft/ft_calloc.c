/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:41 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/17 17:44:29 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	tmp;

	if (size == 0)
		return (NULL);
	tmp = nmemb * size;
	if (tmp / nmemb != size)
		return (NULL);
	array = malloc(tmp);
	if (!array)
	{
		return (NULL);
	}
	ft_bzero(array, nmemb);
	return (array);
}
