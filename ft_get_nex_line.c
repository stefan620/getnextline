/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nex_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:46:11 by silic             #+#    #+#             */
/*   Updated: 2024/09/30 19:39:10 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ft_getnextline.h"
#define BUFFER_SIZE 2

char *get_rest(char *str);
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
	static char *stuff_read;
	int i;
	i = 1;
	static char *save;
	char *save1;

	save = calloc(100, sizeof(char));
	save1 = save;
	while(i)
	{
		stuff_read = get_buff(fd);
		if (!stuff_read)
			return(save1);
		while(*stuff_read)
		{	*save = *stuff_read;
			if(*stuff_read == '\n')
			{
				get_rest(stuff_read);
				return(save1);
			}
			stuff_read++;
			save++;
		}
	}
	return(NULL);
}
char *get_rest(char *str)
{
	char ret[1000];
	if(str)
	{
		while(str)
		{
			
		}
	}
	return(str);
}
char *get_next_line(int fd)
{
	char *line;
	char *prefix;
	line = get_line(fd);
	prefix = get_rest;
	
	return(s);
}
int	main(void)
{
	int fd;
	int i = 0;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while(i< 3)
	{
		printf("%s", get_next_line(fd));
		//printf("%d", BUFFER_SIZE);
		i++;
	}
}