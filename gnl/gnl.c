
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <wel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:06:29 by wel-kass          #+#    #+#             */
/*   Updated: 2023/12/12 03:39:41 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*get_next_line(int fd)
{
	static char	*until_exit;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_SIZE_FD)
		return (NULL);
	read_line(&until_exit, fd);
	if (!until_exit)
		return (NULL);
	line = extract_line(until_exit);
	if (!line)
	{
		free(until_exit);
		until_exit = NULL;
		return (NULL);
	}
	until_exit = clean_until_exit(until_exit, ft_strlen_gnl(line));
	return (line);
}

void	read_line(char **until_exit, int fd)
{
	char	*container;
	int		count;

	while (!ft_strchr_gnl(*until_exit, '\n'))
	{
		container = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		if (container == NULL)
			return ;
		count = read(fd, container, BUFFER_SIZE);
		if (count == 0)
		{
			free(container);
			return ;
		}
		if (count == -1)
		{
			free(container);
			free(*until_exit);
			*until_exit = NULL;
			return ;
		}
		container[count] = '\0';
		*until_exit = ft_strjoin_gnl(*until_exit, container);
		free(container);
	}
}

char	*extract_line(char *until_exit)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (!until_exit || !ft_strlen_gnl(until_exit))
		return (NULL);
	while (until_exit[i] && until_exit[i] != '\n')
		i++;
	if (until_exit[i] && until_exit[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (until_exit[++i] && until_exit[i] != '\n')
		line[i] = until_exit[i];
	if (until_exit[i] && until_exit[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_until_exit(char *until_exit, int len_line)
{
	char	*container;
	int		i;
	int		j;

	i = 0;
	j = 0;
	container = malloc(((ft_strlen_gnl(until_exit) - len_line) + 1) * sizeof(char));
	if (container == NULL)
		return (NULL);
	i = len_line;
	while (until_exit[i])
	{
		container[j] = until_exit[i];
		j++;
		i++;
	}
	container[j] = '\0';
	free(until_exit);
	return (container);
}