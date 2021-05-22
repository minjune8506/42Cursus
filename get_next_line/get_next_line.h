/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:36:49 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/21 21:26:25 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

int			check_newline(char *buff);
int			sep_line(char **line, char **store, int new_line);
int			remain_content(char **line, char **store, int read_size);
int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
