/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nex_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:46:11 by silic             #+#    #+#             */
/*   Updated: 2024/09/29 18:15:13 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

char *get_buff (char *buf, int fd)
{
	char	*buff;
	static int		a;

	a = read(fd, buf, sizeof(buf));
	buff = (char * )calloc(a + 2, sizeof(char));
	buff[a+2] = '\0';
	strcpy(buff, buf);
	return(buff);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	int		i;
	char *buff1;
	char *buff2;
	int 			j;
	memset(buff2, '\0', 1000);
	i = 0;
	j = 0;
	buff1 = get_buff(buff, fd);
	while (i > -1)
	{
		i = 0;
		while(buff1[i])
		{
			buff2[j] = buff1[i];
			if (buff1[i] == '\n')
			{
				buff2[j+1] = '\0';
				return(buff2);
			}
			i++;
			j++;
		}
		buff1 = get_buff(buff, fd);
		//if (*buff1 == '\n')
		//	return(NULL);
	}
	return(NULL);
}

int	main(void)
{
	int fd;
	int i = 0;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while(i< 5)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}