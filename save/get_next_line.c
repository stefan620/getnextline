/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:02:23 by silic             #+#    #+#             */
/*   Updated: 2024/10/05 16:32:49 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
static char	*get_rest(char *buff);
static char	*get_line(int fd, char *rest, char *buff);
char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*rest = NULL;

	buff = (char *)calloc(BUFFER_SIZE + 1 , sizeof(char));
	if (!buff)
		return(NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rest);
		free(buff);
		rest = NULL;
		return(NULL);
	}
	line = get_line(fd, rest, buff);
	free(buff);
	if (!line)
	{
		free(line);
		return(NULL);
	}
	if (*line == 0)
    {
		free(line);
		return(NULL);
	}
	rest = get_rest(line);
	return (line);
}
static char	*get_rest(char *buff)
{
	char	*rest;
	int		i;
	
	rest = NULL;
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
		rest = ft_strdup("");
	if (buff[i] == '\n')
	{
		rest = ft_substr(buff, i + 1, ft_strlen(buff) - i);
		buff[i + 1] = '\0';
	}
	return (rest);
}
static char	*get_line(int fd, char *rest, char *buff)
{
	int		i;
	char *tmp;

	i = 1;
	while(i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		//printf("%i", i);
		if (i == 0)
			break;
		if (!rest)
		{
			free(rest);
			rest = ft_strdup("");
		}
		if (i == 0)
			break;
		tmp = rest;
		//free(rest);
		rest = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		memset(buff, '\0', BUFFER_SIZE);
		if (strchr(rest ,'\n'))
			break;
	}
	return(rest);
}/*
int	main(void)
{
	int fd;
	int i = 0;
	char *s;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (i < 1)
	{
		s = get_next_line(fd);
		printf("%s", s);
		// printf("%d", BUFFER_SIZE);
		//free(s);
		i++;
	}
	free(s);
}*/