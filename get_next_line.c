/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:38:02 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/09 20:45:05 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	static char 	*str;
	int		fbyte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fbyte = read(fd, buf, BUFFER_SIZE);
	if (fbyte <= 0)
		return (NULL);
	while (fbyte > 0)
	{
		buf[fbyte] = '\0';
		str = ft_strjoin(str, buf);
		
	}
}