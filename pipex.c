/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 03:12:48 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/10 21:52:39 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include "libft/libft.h"

# define STDOUT 1
# define STDIN 0
# define STDERR 2
# define SIZE 50

int execute(char **path,char **av,char **cmdargs,char **envp)
{
    int i;
	char *cmd;
	i = 0;
	while(path[i])
	{
		cmd = ft_strjoin(path[i], cmdargs[0]);
        if (access(cmd, F_OK) == 0)
        {
            execve(cmd, cmdargs, envp);
        }
        free(cmd);
        i++;
	}
	return(0);
}
void pipex(char **av,char **envp, int c)
{
    char **cmdargs;
    char **path;
    char *str;
    int i = 0;
    while (envp[i])
    {
        if (strncmp (envp[i] , "PATH=", 5) == 0)
            break;
        i++;
    }
    envp[i] += 5;
    path = ft_split(envp[i],':');
    cmdargs = ft_split(av[c],' ');
	    execute(path,av,cmdargs,envp);
    
}

void    redir(char **env, char **av)
{
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();
    if (pid)
    {
        close(fd[1]);
        dup2(fd[0], STDIN);
        waitpid(pid, NULL, 0);
    }
    else
    {
        close(fd[0]);
        dup2(fd[1], STDOUT);
        pipex(av, env, 2);
    }
    
}

int main(int ac, char **av, char **envp)
{
     int f1;
     int f2;
     int i = 0;
    f1 = open(av[1], O_RDONLY);
    f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    dup2(f1, STDIN);
    dup2(f2, STDOUT);
    
    if (ac == 5)
    {
        redir(av, envp);
        pipex(av, envp, 3);
    }
    else
        perror("invalid numbers of arguments");
        
    return (0);
}