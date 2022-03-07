/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:55:30 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/07 17:03:37 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	findchr(char *s, char c)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*s3;

	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (s1[j])
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
