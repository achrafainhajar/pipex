#ifndef PIPEX_H
#define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include "libft/libft.h"
#include <sys/wait.h>

# define STDOUT 1
# define STDIN 0
# define STDERR 2
# define SIZE 50

char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	**ft_charcount(const char *s, char c, char **str, int alloc);
char	**ft_splitcpy(const char *s, char c, char **str, int alloc);
size_t	ft_strlen(const char	*str);
int execute(char **path,char **cmdargs,char **envp);
void pipex(char **av,char **envp, int c);
void    redir(char **env, char **av);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
#endif