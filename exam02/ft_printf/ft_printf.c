#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_format
{
	va_list ap;
	int width;
	int prec;
	int index;
	int ret;
}t_format;

t_format format;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_strchr(char *str, int c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memset(char *str, char c, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t i = 0;

	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memrcpy(void *dest, void *src, size_t r_len, size_t s_len)
{
	if (!dest && !src)
		return (NULL);
	while (s_len > 0)
	{
		((unsigned char *)dest)[r_len - 1] = ((unsigned char *)src)[s_len - 1];
		r_len--;
		s_len--;
	}
	return (dest);
}

char	*ft_strdup(char *str)
{
	char *ret;
	int length = ft_strlen(str);
	int i = 0;

	ret = (char *)malloc(length + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char *str, int len)
{
	char *ret;
	int i = 0;

	if (format.prec == 0)
		return (ft_strdup(""));
	ret = (char *)malloc(len + 1);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		num_len_base(long long n, int base)
{
	int length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= base;
		length++;
	}
	return (length);
}

char	*ft_itoa(long long n)
{
	char *ret;
	int length = num_len_base(n, 10);

	ret = (char *)malloc(length + 1);
	ret[length] = '\0';
	length--;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		n *= -1;
		ret[0] = '-';
	}
	while (n > 0)
	{
		ret[length] = '0' + (n % 10);
		n /= 10;
		length--;
	}
	return (ret);
}

char	*ft_itoa_base(unsigned int n, char *str)
{
	char *ret;
	int length = num_len_base(n, 16);

	ret = (char *)malloc(length + 1);
	ret[length] = '\0';
	length--;
	if (n == 0)
		ret[0] = '0';
	while (n > 0)
	{
		ret[length] = str[n % 16];
		length--;
		n /= 16;
	}
	return (ret);
}

char	*ft_malloc(int len)
{
	char *ret;

	if (format.width > len)
	{
		ret = (char *)malloc(format.width + 1);
		ft_memset(ret, ' ', format.width + 1);
		ret[format.width] = '\0';
	}
	else
	{
		ret = (char *)malloc(len + 1);
		ft_memset(ret, ' ', len + 1);
		ret[len] = '\0';
	}
	return (ret);
}

void	type_s()
{
	char *s_string;
	char *ret;
	int length = 0;

	s_string = va_arg(format.ap, char *);
	if (!s_string)
		s_string = "(null)";
	length = ft_strlen(s_string);
	if (format.prec > -1 && format.prec < ft_strlen(s_string))
		s_string = ft_substr(s_string, format.prec);
	ret = ft_malloc(ft_strlen(s_string));
	ret = ft_memrcpy(ret, s_string, ft_strlen(ret), ft_strlen(s_string));
	if (format.prec > -1 && format.prec < ft_strlen(s_string))
		free(s_string);
	ft_putstr(ret);
	format.index++;
	format.ret += ft_strlen(ret);
	free(ret);
}

char 	*create_pre_str(char *d_string, int len)
{
	char *ret;

	if (*d_string == '-')
	{
		ret = (char *)malloc(format.prec + 2);
		ft_memset(ret, '0', format.prec + 2);
		ret[format.prec + 1] = '\0';
		ret[0] = '-';
		ft_memcpy(&ret[format.prec - len + 2], d_string + 1, len);
	}
	else
	{
		ret = (char *)malloc(format.prec + 1);
		ft_memset(ret, '0', format.prec + 1);
		ret[format.prec] = '\0';
		ft_memcpy(&ret[format.prec - len], d_string, len);
	}
	return (ret);
}

void	type_d()
{
	char *d_string;
	char *ret;
	int num;

	num = va_arg(format.ap, int);
	d_string = ft_itoa(num);
	if (format.prec > -1 && format.prec > ft_strlen(d_string))
		d_string = create_pre_str(d_string, ft_strlen(d_string));
	else if (format.prec == 0 && num == 0)
	{
		free(d_string);
		d_string = ft_strdup("");
	}
	ret = ft_malloc(ft_strlen(d_string));
	ret = ft_memrcpy(ret, d_string, ft_strlen(ret), ft_strlen(d_string));
	ft_putstr(ret);
	format.index++;
	format.ret += ft_strlen(ret);
	free(ret);
	free(d_string);
}

void	type_x()
{
	char *x_string;
	char *ret;
	unsigned int num;
	
	num = va_arg(format.ap, unsigned int);
	x_string = ft_itoa_base(num, "0123456789abcdef");
	if (format.prec > -1 && format.prec > ft_strlen(x_string))
		x_string = create_pre_str(x_string, ft_strlen(x_string));
	else if (format.prec == 0 && num == 0)
	{
		free(x_string);
		x_string = ft_strdup("");
	}
	ret = ft_malloc(ft_strlen(x_string));
	ret = ft_memrcpy(ret, x_string, ft_strlen(ret), ft_strlen(x_string));
	ft_putstr(ret);
	format.index++;
	format.ret += ft_strlen(ret);
	free(ret);
	free(x_string);
}

int		ft_printf(const char *str, ...)
{
	va_start(format.ap, str);
	format.index = 0;
	format.ret = 0;
	while(str[format.index])
	{
		format.width = 0;
		format.prec = -1;
		if (str[format.index] != '%' && str[format.index])
		{
			ft_putchar(str[format.index]);
			format.index++;
			format.ret++;
		}
		else
		{
			format.index++;
			while (!(ft_strchr("sdx", str[format.index])) && str[format.index])
			{
				if (str[format.index]== '.')
					format.prec = 0;
				if (is_digit(str[format.index]))
				{
					if (format.prec == -1)
						format.width = (format.width * 10) + (str[format.index] - '0');
					else
						format.prec = (format.prec * 10) + (str[format.index] - '0');
				}
				format.index++;

			}
			if (str[format.index] == 's')
				type_s();
			else if (str[format.index] == 'd')
				type_d();
			else if (str[format.index] == 'x')
				type_x();
		}
	}
	va_end(format.ap);
	return (format.ret);
}
