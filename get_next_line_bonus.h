/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:10 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/18 04:21:35 by sthitiku         ###   ########.fr       */
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
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		findchr(char *s, char c);
int		bsn_pos(char *s);
char	*sp_strjoin(char *s1, char *s2, size_t fbyte);
// char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif