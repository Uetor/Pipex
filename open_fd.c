#include "pipex.h"

void children(char **paths, char *comun, char **envp, int fdpipe[2])
{
    int     i;
    char    **arguments;
    char    *command;
    int     pid;

    i = 0;
    arguments = ft_split(comun, ' ');
    while(paths[i])
    {
        command = ft_strjoin(paths[i], arguments[0]);
        if (access(command, 0) == 0)
        {
            pid = fork();
            if (pid == 0)
            {  
                close(fdpipe[0]);
                dup2(fdpipe[1], STDOUT_FILENO);
                close(fdpipe[1]);

                execve(command, arguments, envp);
            }
        }
        i++;
    } 
    
}

void children2(char **paths, char *comun, char **envp, int fdpipe[2])
{
    int     i;
    char    **arguments;
    char    *command;
    int     pid;

   
    i = 0;
    arguments = ft_split(comun, ' ');
    while(paths[i])
    {
        command = ft_strjoin(paths[i], arguments[0]);
        if (access(command, 0) == 0)
        {
            pid = fork();
            if (pid == 0)
            {  
                close(fdpipe[0]);
                dup2(fdpipe[0], STDIN_FILENO);
                close(fdpipe[1]);

                execve(command, arguments, envp);
            }
        }
        i++;
    } 
    
}