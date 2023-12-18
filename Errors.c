/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:01:13 by pedrogon          #+#    #+#             */
/*   Updated: 2023/12/18 19:09:34 by pedrogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	not_file(char *argv)
{
	char	*str;

	str = ft_strjoin(argv, ": No such file or directory");
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free(str);
	exit(1);
}

void	error_command(char *argv)
{
	char	*str;

	str = ft_strjoin("Command not found: ", argv);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free(str);
}

void	space_command(t_pipex *pipex)
{
	free(pipex->arguments);
	write(2, "Command not found\n", 19);
	exit (1);
}
