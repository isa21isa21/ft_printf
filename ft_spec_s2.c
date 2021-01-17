/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:03:06 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/17 11:55:47 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_make_non_dash_for_s_2(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[1] < len)
	{
		while (wid_or_accur[0]-- > wid_or_accur[1] && write(1, " ", 1))
			wid_or_accur[3]++;
		while (wid_or_accur[1]-- != 0 && ++wid_or_accur[3])
			ft_putchar(*s++);
	}
	else if (wid_or_accur[1] >= len)
	{
		while (wid_or_accur[0]-- > len && write(1, " ", 1))
			wid_or_accur[3]++;
		wid_or_accur[3] += len;
		ft_putstr(s);
	}
}

char		*ft_make_non_dash_for_s(char *str, char *s, int len, int *wid_acc)
{
	if (wid_acc[0] > 0 && wid_acc[1] < 0)
		ft_make_non_dash_for_s_1(s, len, wid_acc);
	else if (wid_acc[0] < 1 && wid_acc[1] > -1)
	{
		if (wid_acc[1] < len)
			while (wid_acc[1]-- != 0 && ++wid_acc[3])
				ft_putchar(*s++);
		else
		{
			ft_putstr(s);
			wid_acc[3] += len;
		}
	}
	else if (wid_acc[0] > 0 && wid_acc[1] > -1)
		ft_make_non_dash_for_s_2(s, len, wid_acc);
	else
	{
		if (wid_acc[2] > 0)
			return (str);
		ft_putstr(s);
		wid_acc[3] += len;
	}
	return (str);
}

char		*ft_spec_s(char *str, va_list ap, int dsh_zer, int *wid_acc)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (dsh_zer < 0)
		ft_make_dash_for_s(s, len, wid_acc);
	else if (dsh_zer >= 0)
		ft_make_non_dash_for_s(str, s, len, wid_acc);
	return (str);
}
