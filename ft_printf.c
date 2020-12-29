/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:39:46 by cquickbe          #+#    #+#             */
/*   Updated: 2020/12/29 10:15:22 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *l;

	l = s;
	while (n)
	{
		*l = '\0';
		l++;
		n--;
	}
}

void	ft_puthex(unsigned long long int nb)
{
	char	hex[16];
	int		tmp;
	int		i;

	ft_bzero(hex, 16);
	i = 0;
	while (nb)
	{
		tmp = nb % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('A' - 10) : '0'));
		nb /= 16;
		i++;
	}
	while (i >= 0)
	{
		ft_putchar(hex[i]);
		i--;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

int	ft_isdigit_without_zero(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int c;
	long int i;
	long int znak;

	znak = 1;
	i = 0;
	c = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			znak *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + str[i] - '0';
		i++;
	}
	return (c * znak);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	how_nums_in_num(int d)
{
	int i;

	i = 0;
	while (d)
	{
		i++;
		d = d / 10;
	}
	return (i);
}

void	ft_wid_for_d(int d, int how_numb, int dash_or_zero, int *wid_or_accur)
{
	if (dash_or_zero < 0)
	{
		ft_putnbr(d);
		while (wid_or_accur[0]-- > how_numb && write(1, " ", 1))
			wid_or_accur[3]++;
		wid_or_accur[3] += how_numb;
	}
	else if (dash_or_zero > 0)
	{
		if (wid_or_accur[2] > 0)
			while (wid_or_accur[0]-- != how_numb && write(1, " ", 1))
				wid_or_accur[3]++;
		else if (wid_or_accur[2] == 0)
			while (wid_or_accur[0]-- != how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
		ft_putnbr(d);
		wid_or_accur[3] += how_numb;
	}
	else
	{
		while (wid_or_accur[0]-- != how_numb && write(1, " ", 1))
			wid_or_accur[3]++;
		ft_putnbr(d);
		wid_or_accur[3] += how_numb;
	}
}

void	ft_make_accuracy_for_d(int d, int how_numb, int *wid_or_accur)
{
	if (wid_or_accur[1] <= how_numb)
		ft_putnbr(d);
	else if (wid_or_accur[1] > how_numb)
	{
		while (wid_or_accur[1]-- > how_numb && write(1, "0", 1))
			wid_or_accur[3]++;
		ft_putnbr(d);
	}
}

void	ft_wid_acc_for_d(int d, int how_numb, int dash_or_zero, int *wid_or_acc)
{
	int tmp;

	if (dash_or_zero < 0)
	{
		tmp = wid_or_acc[1];
		while (wid_or_acc[1]-- > how_numb && write(1, "0", 1))
			wid_or_acc[3]++;
		ft_putnbr(d);
		while (tmp++ < wid_or_acc[0] && write(1, " ", 1))
			wid_or_acc[3]++;
		wid_or_acc[3] += how_numb;
	}
	else if (dash_or_zero >= 0)
	{
		if (wid_or_acc[1] <= how_numb)
			ft_wid_for_d(d, how_numb, dash_or_zero, wid_or_acc);
		else if (wid_or_acc[1] > how_numb)
		{
			while (wid_or_acc[0]-- > wid_or_acc[1] && write(1, " ", 1))
				wid_or_acc[3]++;
			ft_make_accuracy_for_d(d, how_numb, wid_or_acc);
			wid_or_acc[3] += how_numb;
		}
	}
}

void	ft_make_dash_for_s_one(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[2] > 0)
		while (wid_or_accur[0]-- && write(1, " ", 1))
			wid_or_accur[3]++;
	else if (wid_or_accur[2] == 0)
	{
		ft_putstr(s);
		while (wid_or_accur[0]-- > len && write(1, " ", 1))
			wid_or_accur[3]++;
		wid_or_accur[3] += len;
	}
}

void	ft_make_dash_for_s_two(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[1] < len)
		while (wid_or_accur[1]-- != 0)
			ft_putchar(*s++);
	else
		ft_putstr(s);
}

void	ft_make_dash_for_s_three(char *s, int len, int *wid_or_accur, int tmp)
{
	if (wid_or_accur[1] <= len)
	{
		tmp = wid_or_accur[1];
		while (wid_or_accur[1]-- != 0 && wid_or_accur[3]++)
			ft_putchar(*s++);
		while (wid_or_accur[0]-- > tmp && write(1, " ", 1))
			wid_or_accur[3]++;
	}
	else if (wid_or_accur[1] >= len)
	{
		ft_putstr(s);
		while (wid_or_accur[0]-- > len && write(1, " ", 1))
			wid_or_accur[3]++;
		wid_or_accur[3] += len;
	}
}

void	ft_make_dash_for_s(char *s, int len, int *wid_or_accur)
{
	int tmp;

	tmp = 0;
	if (wid_or_accur[0] > 0 && wid_or_accur[1] < 1)
		ft_make_dash_for_s_one(s, len, wid_or_accur);
	else if (wid_or_accur[0] < 1 && wid_or_accur[1] > 0)
		ft_make_dash_for_s_two(s, len, wid_or_accur);
	else if (wid_or_accur[0] > 0 && wid_or_accur[1] > 0)
		ft_make_dash_for_s_three(s, len, wid_or_accur, tmp);
	else
		ft_putstr(s);
}

void	ft_make_non_dash_for_s_one(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[2] > 0)
		while (wid_or_accur[0]-- && wid_or_accur[3]++)
			write(1, " ", 1);
	else if (wid_or_accur[2] == 0)
	{
		while (wid_or_accur[0]-- > len && write(1, " ", 1))
			wid_or_accur[3]++;
		ft_putstr(s);
		wid_or_accur[3] += len;
	}
}

void	ft_make_non_dash_for_s_two(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[1] < len)
	{
		while (wid_or_accur[0]-- > wid_or_accur[1] && write(1, " ", 1))
			wid_or_accur[3]++;
		while (wid_or_accur[1]-- != 0 && wid_or_accur[3]++)
			ft_putchar(*s++);
	}
	else if (wid_or_accur[1] >= len)
	{
		while (wid_or_accur[0]-- > len && write(1, " ", 1))
			wid_or_accur[3]++;
		ft_putstr(s);
	}
}

void	ft_make_non_dash_for_s(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[0] > 0 && wid_or_accur[1] < 1)
		ft_make_non_dash_for_s_one(s, len, wid_or_accur);
	else if (wid_or_accur[0] < 1 && wid_or_accur[1] > 0)
	{
		if (wid_or_accur[1] < len)
			while (wid_or_accur[1]-- != 0 && wid_or_accur[3]++)
				ft_putchar(*s++);
		else
			ft_putstr(s);
	}
	else if (wid_or_accur[0] > 0 && wid_or_accur[1] > 0)
		ft_make_non_dash_for_s_two(s, len, wid_or_accur);
	else
	{
		if (wid_or_accur[2] > 0)
			return ;
		ft_putstr(s);
		wid_or_accur[3] += len;
	}
}

void	ft_spec_c_one(char c, va_list ap, int dash_zero, int *wid_acc)
{
	if (wid_acc[0] > 0)
	{
		ft_putchar(c);
		while (wid_acc[0]-- > 1 && write(1, " ", 1))
			wid_acc[3]++;
		wid_acc[3] += 1;
	}
	else
	{
		ft_putchar(c);
		wid_acc[3] += 1;
	}
}

void	ft_spec_c(const char *str, va_list ap, int dash_zero, int *wid_acc)
{
	char c;

	if (*str == 'c' && (c = va_arg(ap, int)))
	{
		if (dash_zero < 0)
			ft_spec_c_one(c, ap, dash_zero, wid_acc);
		else if (wid_acc[0] > 0)
		{
			while (wid_acc[0]-- > 1 && write(1, " ", 1))
				wid_acc[3]++;
			ft_putchar(c);
			wid_acc[3] += 1;
		}
		else
		{
			ft_putchar(c);
			wid_acc[3] += 1;
		}
	}
}

void	ft_spec_s(const char *format, va_list ap, int dash_zero, int *wid_acc)
{
	char	*s;
	int	len;

	if (*format == 's' && (s = va_arg(ap, char *)))
	{
		len = ft_strlen(s);
		if (dash_zero < 0)
			ft_make_dash_for_s(s, len, wid_acc);
		else if (dash_zero >= 0)
			ft_make_non_dash_for_s(s, len, wid_acc);
	}
}

void	ft_spec_d_i(const char *format, va_list ap, int dash_zero, int *wid_acc)
{
	int d;
	int how_numb;

	if ((*format == 'd' || *format == 'i') && (d = va_arg(ap, int)))
	{
		how_numb = how_nums_in_num(d);
		if (wid_acc[0] > 0 && wid_acc[1] < 1)
			ft_wid_for_d(d, how_numb, dash_zero, wid_acc);
		else if (wid_acc[0] < 1 && wid_acc[1] > 0)
			ft_make_accuracy_for_d(d, how_numb, wid_acc);
		else if (wid_acc[0] > 0 && wid_acc[1] > 0)
			ft_wid_acc_for_d(d, how_numb, dash_zero, wid_acc);
		else
		{
			wid_acc[3] += how_numb;
			ft_putnbr(d);
		}
	}
}

void ft_spec_x_X(const char *format, va_list ap, int dash_zero, int *wid_acc)
{
	unsigned long long int x;
	int how_numb;

	if((*format == 'x' || *format == 'X') && (x = va_arg(ap, unsigned long long int)))
	{
		how_numb = how_nums_in_num(x);
		if (wid_acc[0] > 0 && wid_acc[1] < 1)
		{
			if (dash_zero < 0)
			{
				ft_puthex(x);
				while (wid_acc[0]-- > how_numb && write(1, " ", 1))
					wid_acc[3]++;
				wid_acc[3] += how_numb;
			}
			else if (dash_zero >= 0)
			{
				while(wid_acc[0]-- > how_numb && write(1, "0", 1))
					wid_acc[3]++;
				wid_acc[3] += how_numb;
				ft_puthex(x);
			}
		}
	}
}

char	*ft_wid_or_acc(char *format, va_list ap, int dash_zero, int *i)
{
	char	*tmp;
	int	wid_or_accur[4];

	wid_or_accur[0] = 0;
	wid_or_accur[1] = 0;
	wid_or_accur[2] = 0;
	wid_or_accur[3] = *i;
	if (ft_isdigit(*format))
	{
		tmp = (char*)format;
		wid_or_accur[0] = ft_atoi(tmp);
		while (ft_isdigit_without_zero(*format))
			format++;
		tmp = "\0";
	}
	if (*format == '.' && !ft_isdigit(*format + 1))
		wid_or_accur[2]++;
	if (*format == '.' && ft_isdigit_without_zero(*(++format)))
	{
		tmp = (char*)format;
		wid_or_accur[1] = ft_atoi(tmp);
		while (ft_isdigit_without_zero(*format))
			format++;
		tmp = "\0";
	}
	ft_spec_c(format, ap, dash_zero, wid_or_accur);
	ft_spec_s(format, ap, dash_zero, wid_or_accur);
	ft_spec_d_i(format, ap, dash_zero, wid_or_accur);
	ft_spec_x_X(format, ap, dash_zero, wid_or_accur);
	*i = wid_or_accur[3];
	return (format);
}

char	*ft_flags(char *format, va_list ap, int *i)
{
	int dash_or_zero_flag;

	dash_or_zero_flag = 0;
	format++;
	while (!ft_isdigit(*format) && *format != 'c' && *format != 's' &&
	*format != 'p' && *format != 'd' && *format != 'i' && *format != 'u' &&
	*format != 'x' && *format != 'X'
	&& *format != '.')
	{
		if (*format == '-' && (format++))
			dash_or_zero_flag--;
		else if (*format == '0' && (format++))
			dash_or_zero_flag++;
	}
	format = ft_wid_or_acc(format, ap, dash_or_zero_flag, i);
	return (format);
}

char	*ft_format(char *format, va_list ap, int *i)
{
	--format;
	while (*(++format) != '\0')
	{
		if (*format == '%')
			format = ft_flags(format, ap, i);
		else
		{
			*i += 1;
			write(1, format, 1);
		}
	}
	return (format);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	char		*tmp;
	va_list	ap;

	i = 0;
	tmp = (char*)format;
	va_start(ap, format);
	tmp = ft_format(tmp, ap, &i);
	va_end(ap);
	return (i);
}

int	main(void)
{
	printf("<%d>\n", printf("hello world |%05X|", 255));
	printf("\n");
	ft_printf("<%d>\n", ft_printf("hello world |%05x|", 255));
	printf("\n");
	return (0);
}
