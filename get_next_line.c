#include "get_next_line.h"

void	new_ost(char **ostatok, char *line)
{
	char	*tmp;

	tmp = 0;
	tmp = ft_strdup(*ostatok + (ft_strlen(line)));
	if (*ostatok)
	{
		free(*ostatok);
		*ostatok = NULL;
	}
	*ostatok = tmp;
}

char	*check(char **ostatok, char *pointer)
{
	char		*tmp;
	int			i;

	if (!pointer && *ostatok)
		tmp = ft_strdup(*ostatok);
	else if (pointer)
	{
		*pointer = '\0';
		i = ft_strlen(*ostatok) + 1;
		*pointer = '\n';
		tmp = ft_substr(*ostatok, 0, i);
	}
	else
	{
		tmp = NULL;
		new_ost(ostatok, tmp);
		return (NULL);
	}		
	new_ost(ostatok, tmp);
	return (tmp);
}

char 	*get_next_line(int fd)
{
	static char	*ostatok;
	char		*buffer;
	int			reader;
	char		*pointer;

	reader = 1;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	pointer = ft_strchr(ostatok, '\n');
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
	return (check(&ostatok, pointer));
}
// int main()
// {
// 	int fd = open("gnlTester-master/files/nl", O_RDONLY);
// 	char *line;
// 	int i;
// 	i = 0;
// 	while((line = get_next_line(fd)))
// 	{

// 		printf("%s",line);
// 	 	free(line);
// 	}
// 	//printf("i = %d %s\n", i, line);
// 	//free(line);
// 	// printf("%s\n", line);
// 	//sleep(1000);
// 	return(0);
// }
