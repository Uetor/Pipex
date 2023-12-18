/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:38:21 by pedrogon          #+#    #+#             */
/*   Updated: 2023/12/18 19:21:04 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**paths;
	char	*cmd;
	char	**envp;
	char	**arguments;
	int		fdpipe[2];
	int		fd;
	int		fd2;
	int		status;
	int		pid;
	int		i;
	int		find;
}	t_pipex;

void	children(char *argv, t_pipex *pipex);
void	aux_children(t_pipex *pipex);
void	children2(char *argv, t_pipex *pipex);
void	aux_children2(t_pipex *pipex);
void	ft_free_memory(char **str);
void	error_command(char *argv);
void	not_file(char *argv);
void	space_command(t_pipex *pipex);

#endif
