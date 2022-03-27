/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:03:50 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/28 01:01:44 by sthitiku         ###   ########.fr       */
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
		// return (read);
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
	t_read	*before;
	t_read	*after;
	t_read	*curr;

	curr = read;
	while (curr->next)
	{
		if (curr->next->fd == fd)
		{
			before = curr;
			after = curr->next->next;
			if (curr->next->str == NULL)
			{
				curr->next->fd = 0;
				curr->next->next = NULL;
				free(curr->next);
				return ;
			}
			before->next = after;
			curr = curr->next;
		}
	}
}
// void	ft_lstadd_back(t_read **lst, t_read *new)
// {
// 	t_read	*temp;

// 	if (lst && new)
// 	{
// 		if (*lst == NULL)
// 			*lst = new;
// 		else
// 		{
// 			temp = ft_lstlast(*lst);
// 			temp->next = new;
// 		}
// 	}
// }

// t_read	*ft_lstlast(t_read *lst)
// {
// 	if (lst)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 	}
// 	return (lst);
// }

// t_read	*ft_lstnew(void *content)
// {
// 	t_read	*new;

// 	new = (t_read *)malloc(sizeof(*new));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// void	ft_lstdelone(t_read *lst, void (*del)(void *))
// {
// 	if (lst && del)
// 	{
// 		del(lst->content);
// 		free(lst);
// 	}
// }
