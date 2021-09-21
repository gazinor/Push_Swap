/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:26:19 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/20 20:13:54 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_append_char(char *str, char c)
{
	int		i;
	char	*str_new;

	i = 0;
	if (c == '\0')
	{
		if (str && (*str || !*str))
			free(str);
		str = NULL;
		return (NULL);
	}
	str_new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = c;
	str_new[i + 1] = '\0';
	free(str);
	str = NULL;
	return (str_new);
}

int	free_and_error(char *str)
{
	if (str && (*str || !*str))
		free(str);
	str = NULL;
	return (-1);
}

int	get_next_line(char **line)
{
	char	c;
	int		ret;
	char	*str;

	c = '\0';
	ret = read(0, &c, 1);
	str = malloc(sizeof(char) * 1);
	str[0] = '\0';
	while (c != '\n' && ret != 0)
	{
	printf("str --> {%s}\n", str);
		if (ret == -1)
		{
			printf("Je passe clairement ici\n");
			return (free_and_error(str));
		}
		else if (c != '\n' && ret != 0)
		{
			str = ft_append_char(str, c);
			if (str == NULL)
				return (-1);
		}
		ret = read(0, &c, 1);
	}
	*line = str;
	if (ret == 0)
		return (0);
	else
		return (1);
}
