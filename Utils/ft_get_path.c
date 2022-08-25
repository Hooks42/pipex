/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:09:12 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/25 15:14:02 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
**	Look for "PATH=" in approx.
**	get all the paths and put them 
**	in a double array.
*/

char	**ft_get_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
	{
		perror("Error: PATH not found");
		exit(PATH_ERROR);
	}
	path = ft_split(env[i] + 5, ':');
	return (path);
}
