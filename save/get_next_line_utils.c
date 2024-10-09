/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:26:01 by silic             #+#    #+#             */
/*   Updated: 2024/10/09 14:52:48 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start + len > i && len != i)
		len = len - 1;
	if (start > i)
		sub = (char *)malloc(sizeof(char));
	else if (len >= i && start <= i)
		sub = (char *)malloc((i - start + 1) * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	if (start > i)
		ft_strlcpy(sub, "", 1);
	else if (len >= i && start <= i)
		ft_strlcpy(sub, s + start, i + 1);
	else
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}
static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (src[j])
		j++;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;
	char	*dup1;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	dup = (char *) malloc(i * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	dup1 = dup;
	while (i-- > 0)
	{
		*dup++ = *s++;
	}
	*dup = '\0';
	return (dup1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	char		*s12;
	char		*ret;
	const char	*counter1 = s1;
	const char	*counter2 = s2;
	const char	*free1 = s1;
	const char	*free2 = s2;

	i = 0;
	while (*s1++ != '\0')
		i++;
	while (*s2++ != '\0')
		i++;
	s12 = (char *)malloc(i * sizeof(char) + 1);
	if (s12 == NULL)
		return (NULL);
	ret = s12;
	while (*counter1 != '\0')
		*s12++ = *counter1++;
	while (*counter2 != '\0')
		*s12++ = *counter2++;
	*s12 = '\0';
	return (free((void *)free1), free((void *)free2), ret);
}
