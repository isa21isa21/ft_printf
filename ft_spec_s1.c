/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:02:27 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/15 13:06:37 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_make_dash_for_s_1(char *s, int len, int *wid_or_accur)
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

void		ft_make_dash_for_s_2(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[1] < len)
		while (wid_or_accur[1]-- != 0 && ++wid_or_accur[3])
			ft_putchar(*s++);
	else
	{
		wid_or_accur[3] += len;
		ft_putstr(s);
	}
}

void		ft_make_dash_for_s_3(char *s, int len, int *wid_or_accur, int tmp)
{
	if (wid_or_accur[1] <= len)
	{
		tmp = wid_or_accur[1];
		while (wid_or_accur[1]-- != 0 && ++wid_or_accur[3])
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

void		ft_make_dash_for_s(char *s, int len, int *wid_or_accur)
{
	int tmp;

	tmp = 0;
	if (wid_or_accur[0] > 0 && wid_or_accur[1] < 0)
		ft_make_dash_for_s_1(s, len, wid_or_accur);
	else if (wid_or_accur[0] < 1 && wid_or_accur[1] > -1)
		ft_make_dash_for_s_2(s, len, wid_or_accur);
	else if (wid_or_accur[0] > 0 && wid_or_accur[1] > -1)
		ft_make_dash_for_s_3(s, len, wid_or_accur, tmp);
	else
	{
		if (wid_or_accur[2] == 1)
			return ;
		else
		{
			wid_or_accur[3] += len;
			ft_putstr(s);
		}
	}
}

void		ft_make_non_dash_for_s_1(char *s, int len, int *wid_or_accur)
{
	if (wid_or_accur[2] > 0)
		while (wid_or_accur[0]-- && ++wid_or_accur[3])
			write(1, " ", 1);
	else if (wid_or_accur[2] == 0)
	{
		while (wid_or_accur[0]-- > len && write(1, " ", 1))
			wid_or_accur[3]++;
		ft_putstr(s);
		wid_or_accur[3] += len;
	}
}
