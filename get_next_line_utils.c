#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	z;

	i = 0;
	if (!s)
		return (NULL);
	z = (int)ft_strlen(s);
	while (i <= z)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	res = malloc(sizeof(char ) * (i + j) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		res[j++] = s1[i++];
	free(s1);
	s1 = NULL;
	i = 0;
	while (s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*s2;
	int		i;

	if (!s1 || *s1 == 0)
		return (NULL);
	len = ft_strlen(s1);
	s2 = malloc(sizeof(*s2) * len + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
