/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:28:25 by jdenis            #+#    #+#             */
/*   Updated: 2023/08/15 00:47:02 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	path = get_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd("unknown command", 2);
		free_all_tab(split_cmd);
		exit(0);
	}
}

int	open_file(char *file, int read_create)
{
	int	fd;

	if (read_create == 0)
		fd = open(file, O_RDONLY, 0777);
	if (read_create == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(0);
	return (fd);
}

void	child(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	close(p_fd[0]);
	dup2(p_fd[1], 1);
	exec(argv[2], env);
}

void	parent(char **argv, int *p_fd, char **env)
{
	int	fd;

	close(p_fd[1]);
	dup2(p_fd[0], 0);
	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	exec(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	parent_id;
	int	pipe_fd[2];

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of arguments", 1);
		exit(1);
	}
	else
	{
		if (pipe(pipe_fd) == -1)
			exit(-1);
		parent_id = fork();
		if (parent_id == -1)
			exit(1);
		if (parent_id == 0)
			child(argv, pipe_fd, env);
		parent(argv, pipe_fd, env);
	}
}
