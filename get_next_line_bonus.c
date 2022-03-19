/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:26 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/20 02:42:33 by sthitiku         ###   ########.fr       */
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
	if (fbyte <= 0)
	{
		if (str[0] != '\0')
			return (str);
		free(str);
		return (NULL);
	}
	while (fbyte > 0)
	{
		tmp = (char *)malloc(ft_strlen(str) + BUFFER_SIZE + 1);
		ft_strlcpy(tmp, str, ft_strlen(str) + 1);
		ft_strlcpy(&tmp[ft_strlen(str)], buf, BUFFER_SIZE + 1);
		free(str);
		if (bsn_pos(tmp) != -1)
			break ;
		fbyte = read(fd, buf, BUFFER_SIZE);
	}
	return (tmp);
}

char	*shift_str(char *str, int pos)
{
	char	*new;
	size_t	new_len;

	if (bsn_pos(str) == -1)
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
	static t_read 	*str;
	int				bsn;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = init_st(str, fd);
	}
	// check_fd()
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
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			ans = get_next_line(fd);
			while (ans)// && j < 4)
			{
				printf("%s", ans);
				ans = get_next_line(fd);
			}
			i++;
			close(fd);
		}
	}
	// fd = open("multiple_line_with_nl", O_RDONLY);
	// // get_next_line(fd);
	// // get_next_line(fd);
	// // get_next_line(fd);
	// // get_next_line(fd);
	// // get_next_line(fd);
	// ans = get_next_line(fd);
	// printf("%s", ans);
	// free(ans);
	// ans = get_next_line(fd);
	// printf("%s", ans);
	// free(ans);
	// ans = get_next_line(fd);
	// printf("%s", ans);
	// free(ans);
	// ans = get_next_line(fd);
	// printf("%s", ans);
	// free(ans);
	// ans = get_next_line(fd);
	// printf("%s", ans);
	// free(ans);
	// ans = get_next_line(fd);
	// printf("%s", ans);
	// free(ans);
}
