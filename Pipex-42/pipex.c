/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:05:25 by aainhaja          #+#    #+#             */
/*   Updated: 2022/05/11 20:05:25 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i != n)
		return (str1[i] - str2[i]);
	return (0);
}

int	execute(char	**path, char		**cmdargs, char	**envp)
{
	int		i;
	char	*cmd;

	i = 0;
	while (path[i])
	{
		cmd = ft_strjoine(path[i], cmdargs[0]);
		if (access(cmd, F_OK) == 0)
		{
			execve(cmd, cmdargs, envp);
		}
		free (cmd);
		i++;
	}
	perror("cmd not found");
	return (0);
}

void	pipex(char **av, char **envp, int c)
{
	char	**cmdargs;
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp (envp[i], "PATH=", 5) == 0)
		{
			break ;
		}
		i++;
	}
	envp[i] = envp[i] + 5;
	path = ft_split(envp[i], ':');
	cmdargs = ft_split(av[c], ' ');
	execute(path, cmdargs, envp);
}

void	redir(char **env, char **av, int i)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		perror("Error in pipe function");
	pid = fork();
	if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT);
		pipex(av, env, i);
	}
	else
	{
		perror("No process created");
	}
}

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;
	int	i;

	i = 2;
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(f1, STDIN);
	dup2(f2, STDOUT);
	if (ac == 5)
	{
		redir(envp, av, i);
		pipex(av, envp, i + 1);
	}
	else
		perror("invalid numbers of arguments");
	return (0);
}
