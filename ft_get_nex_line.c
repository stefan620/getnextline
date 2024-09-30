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
#define BUFFER_SIZE 1

char *get_buff(fd)
{
	static char buff[BUFFER_SIZE];
	static int a;
	char *save;
	static char  *ptr;
	int i = 0;
	int j = 0;
	ptr = (char *)malloc(100 * sizeof(char));
	a = read(fd, buff, sizeof(buff));
	while(buff[i])
	{
		
		ptr[j] = buff[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return(ptr);
}

char *get_next_line(int fd)
{
	char *a = get_buff(fd);
	int i = 0;
	while(a[i] != '\n')
	{	
		i++;
		
	}
	return(a);	
}

int	main(void)
{
	int fd;
	int i = 0;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while(i< 1)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}