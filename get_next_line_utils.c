/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:55:30 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/20 02:33:37 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	bsn_pos(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

char	*sp_strjoin(char *s1, char *s2, size_t fbyte)
{
	size_t	len;
	size_t	ret_len;
	size_t	i;
	char	*s3;

	len = ft_strlen(s1) + fbyte;
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	ret_len = ft_strlen(s1);
	ft_strlcpy(s3, s1, ret_len + 1);
	i = 0;
	while (ret_len + i < len)
	{
		s3[ret_len + i] = s2[i];
		i++;
	}
	s3[ret_len + i] = '\0';
	free(s1);
	return (s3);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}
