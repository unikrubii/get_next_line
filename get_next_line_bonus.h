/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:10 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/31 21:07:03 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct s_read
{
	int				fd;
	char			*str;
	struct s_read	*next;
}				t_read;

size_t	ft_strlen(char *s);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*get_next_line(int fd);
t_read	*init_read(int fd);
t_read	*check_fd(t_read *read, int fd);
void	clear_read(t_read *read, int fd);

#endif