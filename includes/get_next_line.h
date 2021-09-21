/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:09:09 by glaurent          #+#    #+#             */
/*   Updated: 2019/10/29 13:09:16 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				fd;
	int				ret;
	char			*buffer;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(char const *s);
int					ft_isprint(int c);
int					get_next_line(char **line);

#endif
