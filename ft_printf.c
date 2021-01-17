/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:39:46 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/16 13:18:19 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

char	*ft_wid_or_acc_2(char *format, va_list ap, int *wid_or_acc, char *tmp)
{
	if (*format == '.' && !ft_isdigit(*(format + 1)))
	{
		if (*(format + 1) == '*' && (format += 2))
			wid_or_acc[1] = va_arg(ap, int);
		else if (format++)
			wid_or_acc[2]++;
	}
	if (*format == '.' && ft_isdigit(*(format + 1)))
	{
		format++;
		tmp = (char*)format;
		wid_or_acc[1] = ft_atoi(tmp);
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

char	*ft_wid_or_acc(char *format, va_list ap, int dash_zero, int *i)
{
	char	*tmp;
	int		wid_or_accur[4];

	tmp = NULL;
	wid_or_accur[0] = 0;
	wid_or_accur[1] = -1;
	wid_or_accur[2] = 0;
	wid_or_accur[3] = *i;
	if (ft_isdigit(*format))
		format = ft_wid_or_acc_1(format, wid_or_accur, tmp);
	if (*format == '*' && (format++))
	{
		wid_or_accur[0] = va_arg(ap, int);
		if (wid_or_accur[0] < 0 && --dash_zero)
			wid_or_accur[0] *= -1;
	}
	format = ft_wid_or_acc_2(format, ap, wid_or_accur, tmp);
	ft_do_spec(format, ap, dash_zero, wid_or_accur);
	*i = wid_or_accur[3];
	return (format);
}

char	*ft_flags(char *format, va_list ap, int *i)
{
	int dash_or_zero_flag;

	dash_or_zero_flag = 0;
	format++;
	if (*format == '%')
	{
		write(1, "%", 1);
		*i += 1;
		return (format);
	}
	while (!ft_isdigit_zero(*format) && *format != 'c' && *format != 's' &&
	*format != 'p' && *format != 'd' && *format != 'i' && *format != 'u' &&
	*format != 'x' && *format != 'X' && *format != '.' && *format != '*')
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

int		ft_printf(const char *format, ...)
{
	int		i;
	char	*tmp;
	va_list	ap;

	i = 0;
	tmp = (char*)format;
	va_start(ap, format);
	tmp = ft_format(tmp, ap, &i);
	va_end(ap);
	return (i);
}
