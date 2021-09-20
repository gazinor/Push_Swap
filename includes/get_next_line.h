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

char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char const *s2);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(char *str);
t_list				*ft_create_fd(int fd, t_list **list);
t_list				*ft_find_fd(int fd, t_list **list);
int					ft_check(int fd, char **buffer, char **line);
char				*ft_read_n_check(int fd, char *buffer, int *ret);
int					get_next_line(int fd, char **line);

#endif
