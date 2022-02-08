#include "get_next_line_bonus.h"

char	*new_ost(char *ost)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!ost)
		return (NULL);
	while (ost[i] && ost[i] != '\n')
		i++;
	if (ost[i] == '\0')
	{
		free(ost);
		return (NULL);
	}
	if (!(res = malloc(sizeof(char) * ((ft_strlen(ost) - i) + 1))))
		return (NULL);
	i++;
	j = 0;
	while (ost[i])
		res[j++] = ost[i++];
	res[j] = '\0';
	free(ost);
	return (res);
}

char	*get_new_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_read(int fd, char *ostatok)
{
	int		reader;
	char	*line;
	char	*buffer;
	char	*pointer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = 1;
	pointer = ft_strchr(ostatok[fd], '\n');
	while (reader > 0 && !pointer)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader > 0)
		{
			buffer[reader] = 0;
			ostatok = ft_strjoin(ostatok, buffer);
		}
		pointer = ft_strchr(ostatok, '\n');
	}
	free(buffer);
	return (buffer);
}

char 	*get_next_line(int fd)
{
	static char	*ostatok[1024];
	char		*line;

	reader = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || !line)
		return (NULL);
	ostatok[fd] = ft_read(fd, ostatok[fd]);
	if (!ostatok[fd])
		return (NULL);
	line = get_new_line(ostatok[fd]);
	ostatok[fd] = new_ost(ostatok[fd]);
	return (line);
}