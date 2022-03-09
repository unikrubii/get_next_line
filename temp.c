/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:40:24 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/09 15:12:47 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>
# include <fcntl.h>

char	*read_file(char *buf)
{
	static char	*str;
	int		fbyte;
	
	str = ft_strjoin(str, buf);
	return (str);
}

char	*write_ans(char *word)
{
	char	*text;
	char	*ans;
	static int		i;

	word = word + i;
	// printf("%s\n", word);
	while (*word != '\n' && *word != '\0')
	{
		
		i++;
	}
	printf("%d\n", i);
	text = (char *)malloc(sizeof(char) * (i + 1));
	ft_strjoin(text, word);
	printf("%s\n", text);
	if (findchr(text, '\n') || findchr(text, '\0'))
	{
		ans = (char *)malloc(sizeof(char) * (i + 1));
		ft_strlcpy(ans, text, i + 1);
		free(text);
	}
	// printf("%s\n", ans);
	return (0);
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
		buf[fbyte] = '\0';
		tmp = read_file(buf);
		// printf("%s\n", tmp);
		// if (findchr(tmp, '\n'))
		// 	printf("%s\n", write_ans(tmp));
		write_ans(tmp);
		printf("\n");
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