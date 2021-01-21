/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:39:18 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/17 16:56:52 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		how_nums_in_uint(unsigned int u)
{
	int i;

	i = 0;
	while (u)
	{
		i++;
		u = u / 10;
	}
	return (i);
}

int		ft_how_nums_in_u(unsigned int n)
{
	if (n <= 0)
		n = n - 4294967294;
	if (n >= 10)
		ft_how_nums_in_u(n / 10);
	return (how_nums_in_uint(n));
}

char	*ft_do_spec(char *format, va_list ap, int *dash_zero, int *wid_accur)
{
	if (*format == '%')
		ft_spec_perc(format, dash_zero, wid_accur);
	if (*format == 'c')
		ft_spec_c(ap, dash_zero, wid_accur);
	if (*format == 's')
		ft_spec_s(format, ap, dash_zero, wid_accur);
	if (*format == 'p')
		ft_spec_p(format, ap, dash_zero, wid_accur);
	if (*format == 'd' || *format == 'i')
		ft_spec_di(format, ap, dash_zero, wid_accur);
	if (*format == 'u')
		ft_spec_u(format, ap, dash_zero, wid_accur);
	if (*format == 'x')
		ft_spec_x(format, ap, dash_zero, wid_accur);
	if (*format == 'X')
		ft_spec_x_up(format, ap, dash_zero, wid_accur);
	return (format);
}

char	*ft_wid_or_acc_1(char *format, int *wid_or_acc, char *tmp)
{
	if (ft_isdigit(*format))
	{
		tmp = format;
		wid_or_acc[0] = ft_atoi(tmp);
		while (ft_isdigit(*format))
			format++;
		tmp = "\0";
	}
	return (format);
}
