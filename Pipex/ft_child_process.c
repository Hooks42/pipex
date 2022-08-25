/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:10:52 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 16:05:52 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
**	Closes the read end of the PIPE.
**	Transform stdinFD to fd2
**	and stdoutFD at the write end.
**	Execute the command.
*/

void	ft_child_process(int fd1, int *pipefd, char *cmd, char *env[])
{
	close(pipefd[0]);
	if (fd1 >= 0)
		dup2(fd1, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	close(fd1);
	if (fd1 >= 0)
		ft_execute(cmd, env);
	exit(CHILD_PROCESS_ERROR);
}
