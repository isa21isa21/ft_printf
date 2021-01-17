/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:06:38 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/17 12:19:25 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_for_u_2(unsigned int d, int how_numb, int *wid_acc)
{
	if (d == 0 && wid_acc[2] > 0)
		write(1, " ", 1);
	else
		ft_putuint(d);
	if (d < 0)
		how_numb++;
	while (wid_acc[0]-- > how_numb && write(1, " ", 1))
		wid_acc[3]++;
}

void		ft_wid_for_u(unsigned int d, int how_numb, int dsh_zr, int *wid_acc)
{
	if (dsh_zr < 0)
		ft_wid_for_u_2(d, how_numb, wid_acc);
	else if (dsh_zr > 0)
	{
		if (wid_acc[2] > 0)
			while (wid_acc[0]-- != how_numb && write(1, " ", 1))
				wid_acc[3]++;
		else if (wid_acc[2] == 0)
			while (wid_acc[0]-- != how_numb && write(1, "0", 1))
				wid_acc[3]++;
		ft_putuint(d);
	}
	else
	{
		while (wid_acc[0]-- > how_numb && write(1, " ", 1))
			wid_acc[3]++;
		if (d == 0 && wid_acc[2] > 0)
		{
			write(1, " ", 1);
			wid_acc[3]++;
			return ;
		}
		ft_putuint(d);
	}
	wid_acc[3] += how_numb;
}

void		ft_make_acc_for_u(unsigned int d, int how_numb, int *wid_or_accur)
{
	if (wid_or_accur[1] <= how_numb)
	{
		if (d == 0)
			return ;
		ft_putuint(d);
	}
	else if (wid_or_accur[1] > how_numb)
	{
		if (d < 0)
		{
			write(1, "-", 1);
			while (wid_or_accur[1]-- > how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
			ft_putuint(d * (-1));
			wid_or_accur[3]++;
		}
		else if (d >= 0)
		{
			while (wid_or_accur[1]-- > how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
			ft_putuint(d);
		}
	}
	wid_or_accur[3] += how_numb;
}

void		ft_wid_acc_u(unsigned int u, int how_numb, int dsh_zr, int *wid_acc)
{
	int tmp;

	if (dsh_zr < 0)
	{
		tmp = wid_acc[1];
		wid_acc[3] += how_numb;
		if (wid_acc[0] <= wid_acc[1] && wid_acc[1] > how_numb)
		{
			(u < 0) ? write(1, "-", 1) && how_numb-- : 1;
			while (wid_acc[1]-- > how_numb && write(1, "0", 1))
				wid_acc[3]++;
			(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
		}
		else if (wid_acc[0] > wid_acc[1] && wid_acc[1] > how_numb)
			ft_wid_acc_u_3(u, how_numb, wid_acc, tmp);
		else if (wid_acc[0] >= wid_acc[1] && wid_acc[1] < how_numb)
			ft_wid_acc_u_2(u, how_numb, wid_acc);
	}
	else if (dsh_zr >= 0)
		ft_wid_acc_u_1(u, how_numb, dsh_zr, wid_acc);
}

void		ft_spec_u(char *format, va_list ap, int dash_zr, int *wid_acc)
{
	unsigned int	u;
	int				how_numb;

	u = va_arg(ap, int);
	how_numb = ft_how_nums_in_u(u);
	if (u == 0 && (*(format - 1) == '.' && !ft_isdigit(*(format - 2))))
		return ;
	if (wid_acc[0] > 0 && wid_acc[1] < 0)
		ft_wid_for_u(u, how_numb, dash_zr, wid_acc);
	else if (wid_acc[0] < 1 && wid_acc[1] > -1)
		ft_make_acc_for_u(u, how_numb, wid_acc);
	else if (wid_acc[0] > 0 && wid_acc[1] > -1)
		ft_wid_acc_u(u, how_numb, dash_zr, wid_acc);
	else
	{
		wid_acc[3] += how_numb;
		if (u < 0)
			wid_acc[3]++;
		ft_putuint(u);
	}
}
