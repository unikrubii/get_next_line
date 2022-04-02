/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:03:50 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/02 15:07:30 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize || !src)
		return ;
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

t_read	*init_read(int fd)
{
	t_read	*new;

	// printf("malloc struct\n");
	new = (t_read *)malloc(sizeof(t_read));
	if (!new)
		return (NULL);
	new->fd = fd;
	// printf("malloc str\n");
	new->str = (char *)malloc(sizeof(char));
	new->str[0] = '\0';
	new->next = NULL;
	return (new);
}

t_read	*check_fd(t_read *read, int fd)
{
	t_read	*curr;
	t_read	*ret;

	// printf("read = %p\n", read);
	if (!read)
	{
		read = init_read(fd);
		if (!read)
			return (NULL);
	}
	curr = read;
	// printf("read = %p\tcurr = %p\n", read, curr);
	// printf("curr->fd = %d\tfd = %d\n", curr->fd, fd);
	while (curr->next != NULL)
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
		// printf("ret->str = %s\n", ret->str);
		return (ret);
	}
	return (read);
}

t_read	*clear_read(t_read *read, int fd)
{
	t_read	*after;
	t_read	*curr;

	// printf("read->str = %s\tread->fd = %d\tread->next = %p\n", read->str, read->fd, read->next);
	curr = read;
	after = curr->next;
	if (curr->fd == fd)
	{
		if (curr->str != NULL)
			free(curr->str);
		read = after;
		curr->fd = 0;
		curr->next = NULL;
		free(curr);
		return (after);
	}
	while (after != NULL)
	{
		if (after->fd == fd)
		{
			curr->next = after->next;
			// printf("fd = %d\tstr = %s\n",after->fd, after->str);
			if (after->str != NULL)
				free(after->str);
			after->fd = 0;
			after->next = NULL;
			free(after);
		}
		curr = curr->next;
		after = curr->next;
	}
	return (read);
}
