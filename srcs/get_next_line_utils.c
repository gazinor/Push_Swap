/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:21:33 by glaurent          #+#    #+#             */
/*   Updated: 2019/10/28 15:41:34 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!s[start] || !(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && len--)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		s1_size;
	int		s2_size;

	if (!(s1) && !s2)
		return (NULL);
	if (!(s1))
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	s1_size = 0;
	while (s1[s1_size])
		++s1_size;
	s2_size = 0;
	while (s2[s2_size])
		++s2_size;
	if (!(str = malloc(sizeof(char) * (s1_size + s2_size + 1))))
		return (NULL);
	ft_memcpy(str, s1, s1_size);
	ft_memcpy(str + s1_size, s2, s2_size);
	str[s1_size + s2_size] = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	while (n--)
		*((char*)dest + n) = *((char*)src + n);
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i])
		++i;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
