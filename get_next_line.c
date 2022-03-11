/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:38:02 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/11 20:37:45 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

void	free_ptr(char *str)
{
	free(str);
	str = NULL;
}

char	*read_file(int fd, char *str)
{	
	char	buf[BUFFER_SIZE];
	char	*tmp;
	int		fbyte;

	fbyte = read(fd, buf, BUFFER_SIZE);
	while (fbyte > 0)
	{
		tmp = (char *)malloc(sizeof(char) * (fbyte + 1));
		if (!tmp)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		ft_strlcpy(tmp, buf, fbyte + 1);
		str = sp_strjoin(str, tmp);
		free(tmp);
		if (ft_strchr(str, '\n'))
			break ;
		fbyte = read(fd, buf, BUFFER_SIZE);
	}
	return (str);
}

char	*shift_str(char *str, int pos)
{
	char	*new;

	if (!ft_strchr(str, '\n'))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - pos));
	if (!new)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	ft_strlcpy(new, &str[pos + 1], ft_strlen(str) - pos);
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
	// printf("%s\n", str);
	if (!str)
		return (NULL);
	bsn = bsn_pos(str);
	ret = get_ans(str, bsn);
	if (!ret)
		return (NULL);
	str = shift_str(str, bsn);
	// printf("%s\n-----\n%s\n", ret, str);
	return (ret);
}

// int	main(void)
// {
// 	int	fd;
// 	char *ans;

// 	fd = open("test", O_RDONLY);
// 	ans = get_next_line(fd);
// 	// get_next_line(fd);
// 	printf("%s", ans);
// }