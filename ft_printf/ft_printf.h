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

typedef	struct	s_format
{
	va_list		ap;
	int			per;
	int			flag_minus;
	int			flag_zero;
	int			flag_plus;
	int			flag_blank;
	int			sharp;
	int			width;
	int			dot;
	int			prec;
	int			index;
	int			ret;
	char		type;
}				t_format;

int				ft_printf(const char *str, ...);
void			init_format(t_format *format);
int				get_format(t_format *format, const char *str);
void			init_other(t_format *format);
void			check_per(t_format *format, const char *str);
void			check_dot(t_format *format, const char *str);
void			get_per(t_format *format, const char *str);
void			get_flag(t_format *format, const char *str);
int				get_width(t_format *format, const char *str);
int				get_prec(t_format *format, const char *str);
void			get_type(t_format *format, const char *str);
void			type_c(t_format *format);
void			type_s(t_format *format);
void			type_d(t_format *format);
void			type_u(t_format *format);
void			type_x(t_format *format);
void			type_p(t_format *format);
void			type_per(t_format *format);
char			*check_sign(char *ret);
char			*create_pre_str(t_format *format, char *d_string, int num_len);
char			*minus_flag(char *ret, char *d_string, t_format *format);
char			*control_flag(char *d_string, int num, t_format *format);
void			free_all(char *ret, char *d_string);
int				num_len_base_p(unsigned long n, int base);
char			*ft_itoa_base_p(unsigned long num, char *str);
char			*add_p(char *p_string);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_malloc(t_format *format, int str_len);
void			*ft_memrcpy(void *dest, const void *src,
size_t r_len, size_t s_len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_putchar(char c);
int				is_digit(const char *str, t_format *format);
int				ft_strchr(const char *s, int c);
void			ft_putstr(const char *str, int length);
int				ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_atoi(const char *str, t_format *format);
int				num_len_base(long long n, int base);
char			*ft_itoa(long long n);
char			*ft_itoa_base(unsigned int num, char *str);
#endif
