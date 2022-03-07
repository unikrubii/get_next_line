/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:40:24 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/07 17:01:29 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>
# include <fcntl.h>

char	*read_file(char *buf, int fbyte)
{
	static char	*str;

	printf("%d\n", fbyte);
	str = ft_strjoin(str, buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		fbyte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fbyte = read(fd, buf, BUFFER_SIZE);
	while (fbyte > 0)
	{
		// function read file
		read_file(buf, fbyte);
		fbyte = read(fd, buf, BUFFER_SIZE);
	}
	
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	get_next_line(fd);
}