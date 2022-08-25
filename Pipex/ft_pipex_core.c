/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:15:33 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 16:20:29 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_check_pipe(int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("Error with pipe");
		exit(PIPE_ERROR);
	}
}

static void	ft_check_fork(pid_t pid)
{
	if (pid < 0)
	{
		perror("Error with fork");
		exit(FORK_ERROR);
	}
}

/*
**	calls PIPE , the parent process and the child process.
**	If everything goes well, close the PIPE and wait for
**	the end of the two processes.
*/

void	ft_pipex_core(int fd1, int fd2, char *argv[], char *env[])
{
	int		pipefd[2];
	int		status;
	pid_t	pid_1;
	pid_t	pid_2;

	ft_check_pipe(pipefd);
	pid_1 = fork();
	ft_check_fork(pid_1);
	if (pid_1 == 0)
		ft_child_process(fd1, pipefd, argv[2], env);
	pid_2 = fork();
	ft_check_fork(pid_2);
	if (pid_2 == 0)
		ft_parent_process(fd2, pipefd, argv[3], env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
}
