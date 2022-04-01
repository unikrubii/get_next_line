/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:26 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/01 17:46:29 by sthitiku         ###   ########.fr       */
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
		tmp[0] = '\0';
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
	static t_read 	*readf = NULL;
	char			*ret;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	// printf("readf start = %p\n", readf);
	readf = check_fd(readf, fd);
	if (!readf)
		return (NULL);
	readf->str = read_file(fd, readf->str);
	if (!readf->str || *(readf->str) == '\0')
	{
		clear_read(readf, fd);
		readf = NULL;
		return (NULL);
	}
	ret = get_ans(readf->str);
	if (!ret)
	{
		clear_read(readf, fd);
		readf = NULL;
		return (NULL);
	}
	readf->str = shift_str(readf->str);
	return (ret);
}

int	main(void)
{
	int	fd[4];
	char *ans;
	fd[0] = open("41_with_nl", O_RDWR);
	// ans = get_next_line(1000);
	// printf("%s", ans);
	// free(ans);
	ans = get_next_line(fd[0]);
	printf("fd[0] %s", ans);
	free(ans);

	fd[1] = open("42_with_nl", O_RDWR);
	// ans = get_next_line(1001);
	// printf("%s", ans);
	// free(ans);
	ans = get_next_line(fd[1]);
	printf("fd[1] %s", ans);
	free(ans);

	// fd[2] = open("43_with_nl", O_RDWR);
	// ans = get_next_line(1002);
	// printf("%s", ans);
	// free(ans);
	// ans = get_next_line(fd[2]);
	// printf("%s", ans);
	// free(ans);

	// ans = get_next_line(1003);
	// printf("%s", ans);
	// free(ans);
	ans = get_next_line(fd[0]);
	printf("fd[0] %s", ans);
	free(ans);
	
	// ans = get_next_line(1004);
	// printf("%s", ans);
	// free(ans);
	ans = get_next_line(fd[1]);
	printf("fd[1] %s", ans);
	free(ans);
	
	// ans = get_next_line(1005);
	// printf("%s", ans);
	// free(ans);
	// ans = get_next_line(fd[2]);
	// printf("%s", ans);
	// free(ans);

	
	ans = get_next_line(fd[0]);
	printf("fd[0] %s", ans);
	free(ans);
	ans = get_next_line(fd[1]);
	printf("fd[1] %s", ans);
	free(ans);
	// ans = get_next_line(fd[2]);
	// printf("%s", ans);
	// free(ans);
}
