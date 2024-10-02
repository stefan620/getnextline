/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silic <silic@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:08:26 by silic             #+#    #+#             */
/*   Updated: 2024/10/02 14:04:44 by silic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H

# include <stdarg.h>
# include <unistd.h>
char	*ft_strchr(const char *str, int search_str);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif