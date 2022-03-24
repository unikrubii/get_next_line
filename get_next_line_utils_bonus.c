/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:03:50 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/23 16:01:34 by sthitiku         ###   ########.fr       */
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

t_read	*init_read(t_read *read, int fd)
{
	read = (t_read *)malloc(sizeof(t_read));
	read->fd = fd;
	read->str = (char *)malloc(sizeof(char));
	read->str[0] = '\0';
	read->next = NULL;
	return (read);
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
