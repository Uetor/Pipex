/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:43:14 by pedrogon          #+#    #+#             */
/*   Updated: 2023/12/18 19:22:37 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	children(char *argv, t_pipex *pipex)
{
	pipex->i = 0;
	pipex->find = 0;
	pipex->arguments = ft_split(argv, ' ');
	if (pipex->arguments[0] == NULL)
		space_command(pipex);
	while (pipex->paths[pipex->i])
	{
		pipex->cmd = ft_strjoin(pipex->paths[pipex->i], pipex->arguments[0]);
		if (access(pipex->cmd, 0) == 0)
		{
			pipex->find = 1;
			pipex->pid = fork();
			if (pipex->pid == 0)
				aux_children(pipex);
		}
		free(pipex->cmd);
		pipex->i++;
	}
	if (pipex->find == 0)
		error_command(argv);
	ft_free_memory(pipex->arguments);
}

void	children2(char *argv, t_pipex *pipex)
{
	pipex->i = 0;
	pipex->find = 0;
	pipex->arguments = ft_split(argv, ' ');
	if (pipex->arguments[0] == NULL)
		space_command(pipex);
	while (pipex->paths[pipex->i])
	{
		pipex->cmd = ft_strjoin(pipex->paths[pipex->i], pipex->arguments[0]);
		if (access(pipex->cmd, 0) == 0)
		{
			pipex->find = 1;
			pipex->pid = fork();
			if (pipex->pid == 0)
				aux_children2(pipex);
		}
		free(pipex->cmd);
		pipex->i++;
	}
	if (pipex->find == 0)
		error_command(argv);
	ft_free_memory(pipex->arguments);
}

void	aux_children(t_pipex *pipex)
{
	close(pipex->fdpipe[0]);
	dup2(pipex->fdpipe[1], STDOUT_FILENO);
	close(pipex->fdpipe[1]);
	execve(pipex->cmd, pipex->arguments, pipex->envp);
}

void	aux_children2(t_pipex *pipex)
{
	close(pipex->fdpipe[0]);
	dup2(pipex->fdpipe[0], STDIN_FILENO);
	close(pipex->fdpipe[1]);
	dup2(pipex->fd2, STDOUT_FILENO);
	execve(pipex->cmd, pipex->arguments, pipex->envp);
}

void	ft_free_memory(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
