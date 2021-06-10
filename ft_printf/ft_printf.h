/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:53:40 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/08 19:53:41 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef	struct s_format
{
	va_list ap;
	int per;
	int flag_minus;
	int flag_zero;
	int flag_plus;
	int flag_blank;
	int flag_sharp;
	int width;
	int dot;
	int prec;
	int index;
	int ret;
}				t_format;

//ft_printf.c
int		ft_printf(const char *str, ...);
void	init_format(t_format *format);
void	get_format(t_format *format, const char *str);
//check_format.c
void	check_per(t_format *format, const char *str);
void	check_dot(t_format *format, const char *str);
//get_format.c
void	get_per(t_format *format, const char *str);
void	get_flag(t_format *format, const char *str);
void	get_width(t_format *format, const char *str);
void	get_prec(t_format *format, const char *str);
//type.c
void	type_c(t_format *format);
void	type_s(t_format *format);
void	type_d(t_format *format);
//memory.c
void	*ft_memset(void *s, int c, size_t n);
char	*ft_malloc(t_format *format, int str_len);
void	*ft_memrcpy(void *dest, const void *src, size_t r_len, size_t s_len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
//utils.c
void	ft_putchar(char c);
int		ft_atoi(const char *str, t_format *format);
int		is_digit(const char *str, t_format *format);
int		ft_strchr(const char *s, int c);
void	ft_putstr(const char *str, int length);
int		ft_strlen(const char *str);
//utils2.c
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif