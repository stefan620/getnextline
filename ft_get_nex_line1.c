/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nex_line1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:46:11 by silic             #+#    #+#             */
/*   Updated: 2024/09/29 20:18:08 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 1

char	*get_next_line(int fd)
{
	static char	*buff;
	static int		a;
	char		*save;
	int i = 0;
	int j = 0;
	int k = 0;
	//memset(save, '\0', 100);
	
	save =(char *)calloc(1000 + 10, sizeof(char));
	while (k < 100)
	{
		//memset(buff, '\0', BUFFER_SIZE);
		buff =(char *)calloc(BUFFER_SIZE + 10, sizeof(char));

		a = read(fd, buff, sizeof(buff));
		//buff = (char * )calloc(a + 2, sizeof(char));
		buff[a] = '\0';
		while(buff[i])
		{
			if (buff[i] == '\n')
			{
				save = strrchr(buff, '\n') - i;
				free(buff);
				return(save);
			}
			i++;
		}
		i = 0;
		while(buff[i])
		{
			save[j] = buff[i];
			if (save[j] == '\n')
			{	
				free(buff);
				return(save);
			}
			i++;
			j++;
		}
		k++;	
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
	while(i< 3)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}