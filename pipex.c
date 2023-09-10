#include "pipex.h"

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
		tmp  = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
		i++;
	}
	return (paths);
}


int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		fdpipe[2];
	int		status;
	int		fd;
	
	if (argc == 5)
	{
		paths = find_path(envp);
		fd = open(argv[1], O_RDONLY);
   	 	dup2(fd, STDIN_FILENO);
		pipe(fdpipe);
		children(paths, argv[2], envp, fdpipe);
		dup2(fdpipe[0], STDIN_FILENO);
		children2(paths, argv[3], envp, fdpipe);
		close(fdpipe[0]);
		close(fdpipe[1]);
		wait(&status);
		printf("Estamos despues del open_fd\n");
		close(fd);
	}
	else
		write (2, "Incorrect numbers of arguments\n", 32);
	return (0);
}

