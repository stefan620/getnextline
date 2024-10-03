/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nex_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:46:11 by silic             #+#    #+#             */
/*   Updated: 2024/10/03 16:01:35 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD:ft_get_nex_line.c
#include "ft_getnextline.h"
#define BUFFER_SIZE 100

=======
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif
char *get_next_line(int fd);
>>>>>>> refs/remotes/origin/main:get_next_line.c
char *joina(char *line, char *rest);
char *get_buff(int fd)
{
	char *buff;
	int char_read;

	buff = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!buff)
		return(NULL);
	char_read = read(fd, buff, BUFFER_SIZE);
	if(char_read <= 0)
		return(free(buff), NULL);
	return(buff);
}

char *get_line(int fd)
{
	static char *stuff_read = NULL;
	int i;
	i = 1;
	static char *save;
	char *save1;
	static char *rest;

	save = calloc(100, sizeof(char));
	save1 = save;
	while(i)
	{
		stuff_read = get_buff(fd);
		
		if (!stuff_read)
		{
			save1  = save;
			rest++;
			while(*rest != '\n')
			{
				*save = *rest;
				save++;
				rest++;
			}
				*save = '\n';
			if(*rest == '\n')
				return (save1);
			else
				return(NULL);
		}
		while(*stuff_read)
		{	*save = *stuff_read;
			if(*stuff_read == '\n' && !rest)
			{
				rest = strchr(stuff_read, '\n');
				return(save1);
			}
			else if (*stuff_read == '\n' && rest)
				return(joina(save1, rest + 1));
		
			stuff_read++;
			save++;
		}
	}
	return(NULL);
}
char *joina(char *line, char *rest)
{
	 char *ret;
	
	ret =  ft_strjoin(rest, line);

	return(ret);
}

char *get_next_line(int fd)
{
	char *line;
	
	//rest = get_rest(fd);
	line = get_line(fd);
	
	printf("%s", line);
	
	
	return(line);
}/*
int	main(void)
{
	int fd;
	int i = 0;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while(i< 20)
	{
		get_next_line(fd);
		//printf("%d", BUFFER_SIZE);
		i++;
	}
}*/