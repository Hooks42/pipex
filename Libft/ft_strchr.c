/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:51:20 by ceatgie           #+#    #+#             */
/*   Updated: 2022/08/23 12:43:16 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (unsigned char)searchedChar)
			return (((char *)string + i));
		i++;
	}
	if ((unsigned char)searchedChar == '\0')
		return (((char *)string) + i);
	return (NULL);
}
