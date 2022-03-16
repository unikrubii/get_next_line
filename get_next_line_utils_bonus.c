/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:03:50 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/16 09:34:13 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	// printf("src = %s\n", src);
	// printf("dst before = %s\n", dst);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		// printf("i = %zu\tdst = %c\tsrc = %c\n",i ,dst[i], src[i]);
		// printf("src = %p\tdst = %p\n", &src[i], &dst[i]);
		i++;
	}
	dst[i] = '\0';
	// printf("dst = %s\n", dst);
	return (ft_strlen(src));
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src || !len)
		return (dst);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			*((char *)dst + len - 1) = *((char *)src + len - 1);
			len--;
		}
	}
	return (dst);
}
