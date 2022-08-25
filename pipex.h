/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:28:28 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 16:07:56 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

# define PIPE_ERROR 1
# define FORK_ERROR 2
# define ARG_ERROR	3
# define CHILD_PROCESS_ERROR 4
# define EXECUTE_ERROR 5
# define PATH_ERROR 6
# define PARENT_PROCESS_ERROR 7

/*
**	LIBFT
*/

void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
**	PIPEX
*/

int		ft_open_file(char *path, int flag);
void	ft_pipex_core(int fd1, int fd2, char *argv[], char *env[]);
int		pipex(int argc, char *argv[], char *env[]);

/*
**	UTILS
*/

void	ft_child_process(int fd1, int *pipefd, char *cmd, char *env[]);
void	ft_execute(char	*cmd, char	**env);
void	ft_free(char **str);
char	**ft_get_path(char **env);
void	ft_parent_process(int fd2, int	*pipefd, char *cmd, char *env[]);

#endif