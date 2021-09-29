/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:09:09 by glaurent          #+#    #+#             */
/*   Updated: 2021/09/29 07:51:28 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

# include "string.h"

typedef struct s_gnl
{
	char		*buf;
	int			count;
	int			i;
	int			nl;
	int			fd;
}				t_gnl;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				get_next_line(int const fd, char **line);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_memdel(void **ap);
char			*ft_strmerge(char *s1, char *s2);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);

#endif
