/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nex_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:46:11 by silic             #+#    #+#             */
/*   Updated: 2024/09/28 20:15:46 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 10
char *check(int fd);
char	*get_next_line(int fd)
{
	static int	a;
	static char		buff[BUFFER_SIZE];
	int			i;

	i = 0;
	a = read(fd, buff, sizeof(buff));
	buff[a] = '\0';
	return(buff);
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