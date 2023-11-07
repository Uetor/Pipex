/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:38:21 by pedrogon          #+#    #+#             */
/*   Updated: 2023/11/07 03:22:37 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../Libft/libft.h" //Hay que poner toda la ruta del libft para poder encontrarla.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void children(char **paths, char *comun, char **envp, int fdpipe[2]);
void children2(char **paths, char *comun, char **envp, int fdpipe[2], int fd2);

#endif
