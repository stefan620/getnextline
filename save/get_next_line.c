/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:02:23 by silic             #+#    #+#             */
/*   Updated: 2024/10/09 15:07:51 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
static char	*get_rest(char *buff);
static char	*get_line(int fd, char *rest);
char	*get_next_line(int fd)
{
	char		*line = NULL;
	static char	*rest = NULL;

	
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rest);
		free(line);
		rest = NULL;
		return(NULL);
	}
	line = get_line(fd, rest);
	if (!line)
	{	
		free(rest);
		free(line);
		rest = NULL;
		return(NULL);
	}
	if(*line == 0)
	{
		free(rest);
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
	
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[0] == 0 || buff[i] == 0)
		return(NULL);
	rest = ft_substr(buff, i + 1, ft_strlen(buff) - i);
	buff[i + 1] = '\0';
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
	}
	return (rest);
}
static char	*get_line(int fd, char *rest)
{
	int		i;
	char *tmp;
	char *buff;

	i = 1;
	while(i)
	{
		buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!buff)
			return(NULL);
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return(free(buff), NULL);
		buff[i] = 0;
		if (i == 0)
		{	
			free(buff);
			break;
		}
		if (!rest)
		{
			free(rest);
			rest = ft_strdup("");
		}
		tmp = rest;
		if (rest)
			rest = ft_strjoin(tmp, buff);
		if (rest && strchr(rest ,'\n'))
			break;
	}
	return(rest);
}
int	main(void)
{
	int fd;
	int i = 0;
	char *s;

	fd = open("giant_line.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < 2)
	{
		s = get_next_line(fd);
		printf("%s", s);
		//printf("%d", i);
		free(s);
		i++;
	}
	//free(s);
}