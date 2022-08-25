/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:14:33 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 15:41:00 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
**	Opening the file takes as a parameter the path to the latter
**	and the flag for the opening modes.
**	0777 for rights.
*/

int	ft_open_file(char *path, int flag)
{
	int	fd;

	fd = open(path, flag, 0777);
	if (fd < 0)
		perror("Error");
	return (fd);
}
