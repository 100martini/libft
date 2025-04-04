/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:06:23 by wel-kass          #+#    #+#             */
/*   Updated: 2023/12/11 08:07:11 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	if (len_s1 > SIZE_MAX - len_s2 - 1)
		return (NULL);
	new = malloc(len_s1 + len_s2 + 1);
	if (!new)
		return (NULL);
	ft_memcpy_gnl(new, s1, len_s1);
	ft_memcpy_gnl(new + len_s1, s2, len_s2);
	new[len_s1 + len_s2] = '\0';
	free(s1);
	s1 = NULL;
	return (new);
}

char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen_gnl(src);
	if (dstsize)
	{
		i = 0;
		while (src[i] && dstsize - 1 > i)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

void	*ft_memcpy_gnl(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*tempsrc;
	unsigned char	*tempdst;

	if (dst == src)
		return (dst);
	i = 0;
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dst;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}
