/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:05:57 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:41:56 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_acc_for_d_2(int d, int how_numb, int *wid_acc)
{
	(d < 0 && d != -2147483648) ? write(1, "-", 1) && how_numb-- : 1;
	while (wid_acc[1]-- > how_numb && write(1, "0", 1))
		wid_acc[3]++;
	(d < 0 && d != -2147483648) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
}

void		ft_wid_acc_for_d_3(int d, int num, int *wid_acc, int tmp)
{
	(d < 0 && d != -2147483648) ? write(1, "-", 1) && num-- && wid_acc[0]-- : 1;
	while (tmp-- > num && write(1, "0", 1))
		wid_acc[3]++;
	(d < 0 && d != -2147483648) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
		wid_acc[3]++;
}

void		ft_wid_acc_for_d(int d, int n, int *dsh_or_zr, int *w)
{
	int tmp;

	if (dsh_or_zr[0] > 0)
	{
		tmp = w[1];
		w[3] += n;
		if (w[0] <= w[1] && w[1] >= n)
			ft_wid_acc_for_d_2(d, n, w);
		else if (w[0] <= w[1] && w[1] <= n)
			ft_putnbr(d);
		else if (w[0] > w[1] && w[1] >= n)
			ft_wid_acc_for_d_3(d, n, w, tmp);
		else if (w[0] >= w[1] && w[1] < n)
		{
			(d < 0 && d != -2147483648) ? write(1, "-", 1) && n-- && w[0]-- : 1;
			if (d == 0)
				write(1, " ", 1);
			else
				(d < 0 && d != -2147483648) ? ft_putnbr(d * -1) : ft_putnbr(d);
			while (w[0]-- > n && write(1, " ", 1))
				w[3]++;
		}
	}
	else if (dsh_or_zr[1] > 0 || (dsh_or_zr[0] == 0 && dsh_or_zr[1] == 0))
		ft_wid_acc_for_d_1(d, n, dsh_or_zr, w);
}

void		ft_spec_di(char *format, va_list ap, int *dsh_zr, int *wid_acc)
{
	int d;
	int how_numb;

	d = va_arg(ap, int);
	how_numb = how_nums_in_d(d);
	if (d <= 0)
		how_numb++;
	if (d == 0 && (*(format - 1) == '.' && !ft_isdigit(*(format - 2))))
		return ;
	else if (wid_acc[0] > 0 && wid_acc[1] < 0)
		ft_wid_for_d(d, how_numb, dsh_zr, wid_acc);
	else if (wid_acc[0] < 1 && wid_acc[1] > -1)
		ft_make_accuracy_for_d(d, how_numb, wid_acc);
	else if (wid_acc[0] > 0 && wid_acc[1] > -1)
		ft_wid_acc_for_d(d, how_numb, dsh_zr, wid_acc);
	else
	{
		if (d == 0 && wid_acc[2] > 0)
			return ;
		wid_acc[3] += how_numb;
		ft_putnbr(d);
	}
}
