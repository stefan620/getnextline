/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:02:23 by silic             #+#    #+#             */
/*   Updated: 2024/10/03 19:29:26 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif
char	*get_rest(char *buff);
char	*get_line(int fd, char *rest, char *buff);
char	*get_next_line(fd)
{
	char		*buff;
	char		*line;
	static char	*rest;
	int			a;

	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	line = get_line(fd, rest, buff);
	free(buff);
	rest = get_rest(line);
	return (line);
}
char	*get_rest(char *buff)
{
	char	*rest;
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
		rest = ft_strdup("");
	else if (buff[i] == '\n')
		rest = ft_substr(buff, i + 1, ft_strlen(buff) - i);
	buff[i + 1] = '\0';
	return (rest);
}
char	*get_line(int fd, char *rest, char *buff)
{
	char	*line;
	int		i;
	int		j;
	char *tmp;

	i = 1;
	j = 0;
	while(i)
	{
		j = read(fd, buff, BUFFER_SIZE);
		
		if (!rest)
		{
			free(rest);
			rest = ft_strdup("");
		}
		tmp = rest;
		//free(rest);
		rest = ft_strjoin(tmp, buff);
		
		if (strchr(rest ,'\n'))
			break;
			
	}
	return(rest);
}
int	main(void)
{
	int fd;
	int i = 0;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (i < 1)
	{
		printf("%s", get_next_line(fd));
		// printf("%d", BUFFER_SIZE);
		i++;
	}
}