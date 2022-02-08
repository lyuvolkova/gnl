/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgrodd <qgrodd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:09:17 by qgrodd            #+#    #+#             */
/*   Updated: 2022/02/08 20:09:17 by qgrodd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new_ost(char *ost)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (ost[i] != '\0' && ost[i] != '\n')
		i++;
	if (ost[i] == '\0')
	{
		free(ost);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(ost) - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (ost[i++])
		res[j++] = ost[i];
	res[j] = '\0';
	free(ost);
	return (res);
}

char	*get_new_line(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_read(int fd, char *ostatok)
{
	int		reader;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (reader > 0 && !(ft_strchr(ostatok, '\n')))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[reader] = '\0';
		ostatok = ft_strjoin(ostatok, buffer);
	}
	free(buffer);
	return (ostatok);
}

char	*get_next_line(int fd)
{
	static char	*ostatok[65536];
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ostatok[fd] = ft_read(fd, ostatok[fd]);
	if (!ostatok[fd])
		return (NULL);
	line = get_new_line(ostatok[fd]);
	ostatok[fd] = new_ost(ostatok[fd]);
	return (line);
}
