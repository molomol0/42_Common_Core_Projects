/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:41:59 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/08 15:18:15 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	index_cesar(unsigned int i, char* c)
// {
// 	*c = *c + i;
// }
// #include <stdio.h>
// int main(void)
// {
// 	char s[] = "abcdef";
// 	printf("%s\n", s);
// 	ft_striteri(s, &index_cesar);
// 	printf("%s\n", s);
// }