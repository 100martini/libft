/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 03:42:44 by wel-kass          #+#    #+#             */
/*   Updated: 2023/12/12 03:42:48 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# ifndef MAX_SIZE_FD
#  define MAX_SIZE_FD 1024
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

char	*get_next_line(int fd);
void	read_line(char **until_exit, int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s1);
void	*ft_memcpy_gnl(void *dst, void *src, size_t n);
size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize);
char	*clean_until_exit(char *until_exit, int len_line);
char	*extract_line(char *until_exit);

#endif