/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:26 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/18 18:12:33 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

char	*read_file(int fd, char *str)
{
	char	buf[BUFFER_SIZE];
	int		fbyte;

	fbyte = read(fd, buf, BUFFER_SIZE);
	if (fbyte <= 0)
	{
		if (str[0] != '\0')
			return (str);
		free(str);
		str = NULL;
		return (NULL);
	}
	while (fbyte > 0)
	{
		str = sp_strjoin(str, buf, fbyte);
		if (ft_strchr(str, '\n'))
			break ;
		fbyte = read(fd, buf, BUFFER_SIZE);
	}
	return (str);
}

char	*shift_str(char *str, int pos)
{
	char	*new;
	size_t	new_len;

	if (!ft_strchr(str, '\n'))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	new_len = ft_strlen(str) - pos;
	new = (char *)malloc(sizeof(char) * new_len);
	if (!new)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	ft_strlcpy(new, &str[pos + 1], new_len);
	free(str);
	str = NULL;
	return (new);
}

char	*get_ans(char *str, int pos)
{
	char	*ans;

	if (pos < 0)
	{
		ans = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!ans)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		ft_strlcpy(ans, str, ft_strlen(str) + 1);
		return (ans);
	}
	ans = (char *)malloc(sizeof(char) * (pos + 2));
	if (!ans)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	ft_strlcpy(ans, str, pos + 2);
	return (ans);
}

char	*get_next_line(int fd)
{
	static char 	*str = NULL;
	int				bsn;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	bsn = bsn_pos(str);
	ret = get_ans(str, bsn);
	if (!ret)
		return (NULL);
	str = shift_str(str, bsn);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	fd;
	char *ans;
	// int	i;

	// i = 1;
	// if (argc > 1)
	// {
	// 	while (i < argc)
	// 	{
	// 		fd = open(argv[i], O_RDONLY);
	// 		ans = get_next_line(fd);
	// 		while (ans)// && j < 4)
	// 		{
	// 			printf("%s", ans);
	// 			ans = get_next_line(fd);
	// 		}
	// 		i++;
	// 		close(fd);
	// 	}
	// }
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	fd = open("multiple_line_with_nl", O_RDONLY);
	ans = get_next_line(fd);
	printf("%s", ans);
	free(ans);
	ans = get_next_line(fd);
	printf("%s", ans);
	free(ans);
	ans = get_next_line(fd);
	printf("%s", ans);
	free(ans);
	ans = get_next_line(fd);
	printf("%s", ans);
	free(ans);
	ans = get_next_line(fd);
	printf("%s", ans);
	free(ans);
}
