/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:02:23 by silic             #+#    #+#             */
/*   Updated: 2024/10/11 15:32:35 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000
#endif

static char	*get_rest(char *line);
static char	*get_line(int fd, char *rest, char *buff);
static char	*ft_strchr(const char *str, int search_str);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest = NULL;
	char		*buff;

	line = NULL;
	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(rest), free(line), free(buff), buff = NULL, rest = NULL,
			NULL);
	if (!buff)
		return (NULL);
	line = get_line(fd, rest, buff);
	free(buff);
	buff = NULL;
	if (!line)
		return (free(rest), free(line), free(buff), rest = NULL, NULL);
	if (*line == 0)
		return (free(rest), free(line), NULL);
	rest = get_rest(line);
	return (line);
}

static char	*get_rest(char *line)
{
	char	*rest;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[0] == 0 || line[i] == 0)
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!rest)
		return (free(rest), rest = NULL, NULL);
	if (rest[0] == 0)
		return (free(rest), NULL);
	line[i + 1] = '\0';
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
	}
	return (rest);
}

static char	*get_line(int fd, char *rest, char *buff)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buff[i] = 0;
		if (i == 0)
			break ;
		if (!rest)
			rest = ft_strdup("");
		tmp = rest;
		if (!tmp || !rest)
			return (free(rest), NULL);
		if (rest)
			rest = ft_strjoin(tmp, buff);
		if (rest && ft_strchr(rest, '\n'))
			break ;
	}
	return (rest);
}

static char	*ft_strchr(const char *str, int search_str)
{
	unsigned char	*ptr;
	unsigned char	*ptr1;

	ptr1 = (unsigned char *)&search_str;
	ptr = (unsigned char *)str;
	while (*ptr != '\0')
	{
		if (*ptr == *ptr1)
		{
			return ((char *)ptr);
		}
		ptr++;
	}
	if (*ptr1 == 0)
		return ((char *)ptr);
	return (0);
}
/*
int	main(void)
{
	int fd;
	int i = 0;
	char *s;

	fd = open("giant_line.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < 1)
	{
		s = get_next_line(fd);
		printf("%s", s);
		//printf("%d", i);
		free(s);
		i++;
	}

}*/