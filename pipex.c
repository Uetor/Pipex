/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:10:36 by pedrogon          #+#    #+#             */
/*   Updated: 2023/12/18 19:24:09 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	ft_leaks(void)
{
	system("leaks -q 'pipex'");
} */

char	**find_path(char **envp)
{
	int		i;
	char	*path;
	char	*tmp;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			path = ft_strdup(envp[i]);
		i++;
	}
	paths = ft_split(path + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
		i++;
	}
	free(path);
	return (paths);
}
//atexit(ft_leaks);

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.envp = envp;
	if (argc == 5)
	{
		pipex.paths = find_path(envp);
		pipex.fd = open(argv[1], O_RDONLY);
		if (pipex.fd == -1)
			not_file(argv[1]);
		pipex.fd2 = open(argv[4], O_WRONLY);
		dup2(pipex.fd, STDIN_FILENO);
		pipe(pipex.fdpipe);
		children(argv[2], &pipex);
		dup2(pipex.fdpipe[0], STDIN_FILENO);
		children2(argv[3], &pipex);
		close(pipex.fdpipe[0]);
		close(pipex.fdpipe[1]);
		wait(&pipex.status);
		close(pipex.fd);
		ft_free_memory(pipex.paths);
	}
	else
		write (2, "Incorrect numbers of arguments\n", 32);
	return (0);
}
