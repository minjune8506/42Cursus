/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:16:00 by minjkim2          #+#    #+#             */
/*   Updated: 2021/06/07 09:16:01 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct	s_format
{
	va_list ap;
	int percentage;
	int	index;
	int flag;
	int	width;
	int	result;
	int dot;
}				t_format;

//utils.c
void			ft_putchar(char c);
void			ft_putstr(const char *str);
int				ft_strlen(const char *str);
//ft_printf.c
int				ft_printf(const char *str, ...);
void			init_format(t_format *format);
//flag.c
void			check_flag(const char *str, t_format *format);
void			align(t_format *format);
//width.c
int				is_digit(const char *str, t_format *format);
int				ft_strchr(const char *s, int c);
int				ft_atoi(const char *str, t_format *format);
void			check_width(const char *str, t_format *format);
//dot.c
void			check_dot(const char *str, t_format *format);
//percentage.c
int				check_percentage(const char *str, t_format *format);
void			handle_percentage(const char *str, t_format *format);
//print.c
void			print_type_c(t_format *format);
void			print_type_s(t_format *format);
#endif
