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
	int percentage;
	int	index;
	int flag;
	int	width;
}				t_format;

//utils.c
void			ft_putchar(char c);
void			ft_putstr(const char *str);
//ft_printf.c
int				check_percentage(const char *str, t_format *format);
void			handle_percentage(const char *str, t_format *format);
void			print_type_c(va_list ap, t_format *format);
int				ft_printf(const char *str, ...);
void			init_format(t_format *format);
// int		main(void);
//flag.c
void			check_flag(const char *str, t_format *format);
void			align(t_format *format);
void			fill_zero(const char *str);
//width.c
void			check_width(const char *str, t_format *format);
int				ft_strchr(const char *s, int c);
int				ft_atoi(const char *str, t_format *format);
#endif
