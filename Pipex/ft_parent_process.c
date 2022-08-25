/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:31:15 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 16:06:20 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
**	Closes the write end of the PIPE.
**	Transform stdout FD to fd2
**	and stdinFD at the read end.
**	Execute the command.
*/

void	ft_parent_process(int fd2, int	*pipefd, char *cmd, char *env[])
{
	close(pipefd[1]);
	if (fd2 >= 0)
		dup2(fd2, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(fd2);
	if (fd2 >= 0)
		ft_execute(cmd, env);
	exit(PARENT_PROCESS_ERROR);
}
