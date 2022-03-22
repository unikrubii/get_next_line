/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:38:24 by sthitiku          #+#    #+#             */
/*   Updated: 2022/03/20 02:35:55 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		findchr(char *s, char c);
int		bsn_pos(char *s);
char	*sp_strjoin(char *s1, char *s2, size_t fbyte);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif