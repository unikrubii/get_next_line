/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:03:50 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/31 20:48:09 by sthitiku         ###   ########.fr       */
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

t_read	*init_read(int fd)
{
	t_read	*new;

	new = (t_read *)malloc(sizeof(t_read));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->str = (char *)malloc(sizeof(char));
	new->str[0] = '\0';
	new->next = NULL;
	return (new);
}

t_read	*check_fd(t_read *read, int fd)
{
	t_read	*curr;
	t_read	*ret;

	if (!read)
	{
		read = init_read(fd);
		if (!read)
			return (NULL);
	}
	curr = read;
	while (curr->next)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	if (curr->fd != fd)
	{
		ret = init_read(fd);
		if (!ret)
			return (NULL);
		curr->next = ret;
		return (ret);
	}
	return (read);
}

void	clear_read(t_read *read, int fd)
{
	t_read	*after;
	t_read	*curr;

	// printf("read->str = %s\tread->fd = %d\tread->next = %p\n", read->str, read->fd, read->next);
	curr = read;
	if (curr->fd == fd)
	{
		if (curr->str != NULL)
			free(curr->str);
		read = after;
		curr->fd = 0;
		curr->next = NULL;
		free(curr);
		return ;
	}
	after = curr->next;
	while (after != NULL)
	{
		if (after->fd == fd)
		{
			curr->next = after->next;
			if (after->str != NULL)
				free(after->str);
			after->fd = 0;
			after->next = NULL;
		}
		curr = curr->next;
		after = curr->next;
	}
	return ;
}
