/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:23:45 by jdenis            #+#    #+#             */
/*   Updated: 2023/05/08 15:24:58 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	allocate(char **tab, char const *s, char c)
{
	char		**split;
	char const	*tmp;

	tmp = s;
	split = tab;
	while (*tmp)
	{
		while (*s == c)
			++s;
		tmp = s;
		while (*tmp && *tmp != c)
			++tmp;
		if (*tmp == c || tmp > s)
		{
			*split = ft_substr(s, 0, tmp - s);
			s = tmp;
			++split;
		}
	}
	*split = NULL;
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nb_word;

	if (!s)
		return (NULL);
	nb_word = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!res)
		return (NULL);
	allocate(res, s, c);
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char s[] = "lorem ipsum dolor sit amet,
		// consectetur adipiscing elit. Sed non risus.
//	Suspendisse lectus tortor, dignissim sit amet, adipiscing nec,
		// ultricies sed, dolor.
//	Cras elementum ultricies diam. Maecenas ligula massa, varius a,
		// semper congue, euismod non, mi.";
// 	char c = 'i';
// 	char **split = ft_split(s, c);
// 	int i = 0;
// 	if (split)
// 	{
// 		while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	}
// 	//free_all(split);
// 	return (0);
// }