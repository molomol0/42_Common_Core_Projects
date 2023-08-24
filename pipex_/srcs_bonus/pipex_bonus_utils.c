/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:16:46 by jdenis            #+#    #+#             */
/*   Updated: 2023/08/15 00:38:53 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		var = ft_substr(env[i], 0, j);
		if (ft_strcmp(var, name) == 0)
		{
			free(var);
			return (env[i] + j + 1);
		}
		free(var);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**path_tab;
	char	*path_tmp;
	char	*test_exec;
	char	**s_cmd;

	i = 0;
	path_tab = ft_split(ft_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (path_tab[i + 1])
	{
		path_tmp = ft_strjoin(path_tab[i], "/");
		test_exec = ft_strjoin(path_tmp, s_cmd[0]);
		free(path_tmp);
		if (access(test_exec, F_OK | X_OK) == 0)
		{
			free_all_tab(s_cmd);
			return (test_exec);
		}
		free(test_exec);
		i++;
	}
	free_all_tab(s_cmd);
	free_all_tab(path_tab);
	return (cmd);
}
