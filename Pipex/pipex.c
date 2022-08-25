/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:16:05 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 15:33:32 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
**	If the number of arguments is not 5 returns an error message.
**	open the first file with only read rights then the second with
**	full rights and call pipexcore.
*/

int	pipex(int argc, char *argv[], char *env[])
{
	int	fd_1;
	int	fd_2;

	if (argc != 5)
	{
		ft_putendl_fd("Error: Invalid number of arguments\n", 2);
		ft_putendl_fd("Ex: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
		return (ARG_ERROR);
	}
	fd_1 = ft_open_file(argv[1], O_RDONLY);
	fd_2 = ft_open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	ft_pipex_core(fd_1, fd_2, argv, env);
	return (0);
}
