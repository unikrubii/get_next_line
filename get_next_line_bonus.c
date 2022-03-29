/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:26 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/29 20:11:24 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int	bsn_pos(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_file(int fd, char *str)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	int		fbyte;

	fbyte = read(fd, buf, BUFFER_SIZE);
	if (fbyte <= 0 || str == NULL)
	{
		if (str == NULL || str[0] != '\0')
			return (str);
		free(str);
		return (NULL);
	}
	while (fbyte > 0)
	{
		tmp = (char *)malloc(ft_strlen(str) + fbyte + 1);
		ft_strlcpy(tmp, str, ft_strlen(str) + 1);
		ft_strlcpy(&tmp[ft_strlen(str)], buf, fbyte + 1);
		free(str);
		if (bsn_pos(tmp) != -1)
			break ;
		str = tmp;
		fbyte = read(fd, buf, BUFFER_SIZE);
	}
	return (tmp);
}

char	*shift_str(char *str)
{
	char	*new;
	size_t	new_len;
	int		pos;

	if (bsn_pos(str) == -1)
	{
		free(str);
		return (NULL);
	}
	pos = bsn_pos(str);
	new_len = ft_strlen(str) - pos;
	new = (char *)malloc(sizeof(char) * new_len);
	if (!new)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(new, &str[pos + 1], new_len);
	free(str);
	return (new);
}

char	*get_ans(char *str)
{
	char	*ans;
	int		pos;

	pos = bsn_pos(str);
	if (pos < 0)
	{
		ans = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!ans)
		{
			free(str);
			return (NULL);
		}
		ft_strlcpy(ans, str, ft_strlen(str) + 1);
		return (ans);
	}
	ans = (char *)malloc(sizeof(char) * (pos + 2));
	if (!ans)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(ans, str, pos + 2);
	return (ans);
}

char	*get_next_line(int fd)
{
	static t_read 	*read;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read = check_fd(read, fd);
	if (!read)
		return (NULL);
	// printf("read file in gnl = %s\n", read->str);
	read->str = read_file(fd, read->str);
	// curr = check_fd(read, fd);
	// curr = read;
	// printf("read file = %s\n", read->str);
	if (read->str[0] == '\0' || !read->str)
	{
		// printf("test\n");
		clear_read(read, fd);
		return (NULL);
	}
	ret = get_ans(read->str);
	if (!ret)
	{
		clear_read(read, fd);
		return (NULL);
	}
	// curr = read;
	// printf("read->str before shift = %s\n", read->str);
	// if (read->str == NULL)
	// 	clear_read(read, fd);
	read->str = shift_str(read->str);
	// clear_read(curr, fd);
	// printf("return value = %s\n", ret);
	return (ret);
}

// int	main(int argc, char **argv)
// {
// 	int	fd;
// 	char *ans;
// 	int	i;

// 	i = 1;
// 	if (argc > 1)
// 	{
// 		while (i < argc)
// 		{
// 			fd = open(argv[i], O_RDONLY);
// 			ans = get_next_line(fd);
// 			while (ans)// && j < 4)
// 			{
// 				printf("answer = %s", ans);
// 				ans = get_next_line(fd);
// 			}
// 			i++;
// 			close(fd);
// 		}
// 	}
// }val

// int	main(void)
// {
// 	int	fd;
// 	char *ans;
// 	fd = open("43_with_nl", O_RDONLY);
// 	// // get_next_line(fd);
// 	// // get_next_line(fd);
// 	// // get_next_line(fd);
// 	// // get_next_line(fd);
// 	// // get_next_line(fd);
// 	ans = get_next_line(fd);
// 	printf("%s", ans);
// 	free(ans);
// 	ans = get_next_line(fd);
// 	printf("%s", ans);
// 	free(ans);
// 	ans = get_next_line(fd);
// 	printf("%s", ans);
// 	free(ans);
// 	// ans = get_next_line(fd);
// 	// printf("%s", ans);
// 	// free(ans);
// 	// ans = get_next_line(fd);
// 	// printf("%s", ans);
// 	// free(ans);
// 	// ans = get_next_line(fd);
// 	// printf("%s", ans);
// 	// free(ans);
// 	// ans = get_next_line(fd);
// 	// printf("%s", ans);
// 	// free(ans);
// }
