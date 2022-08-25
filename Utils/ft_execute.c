/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:10:19 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 16:06:10 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
**	split the commands and arguments into an array.
**	Then add to the path "/" + the command.
**	Execute the command.
*/

void	ft_execute(char	*cmd, char	**env)
{
	int		i;
	char	**path;
	char	**cmd_argument;

	i = 0;
	cmd_argument = ft_split(cmd, ' ');
	path = ft_get_path(env);
	if (ft_strchr(cmd_argument[0], '/') != NULL)
		execve(cmd_argument[0], cmd_argument, env);
	else
	{
		while (path[i])
		{
			path[i] = ft_strjoin_free(path[i], "/");
			path[i] = ft_strjoin_free(path[i], cmd_argument[0]);
			execve(path[i], cmd_argument, env);
			i++;
		}
		ft_free(path);
	}
	ft_free(cmd_argument);
	ft_putendl_fd("Error: Command not found", 1);
	exit(EXECUTE_ERROR);
}
