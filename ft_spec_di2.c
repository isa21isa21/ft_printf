/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:05:57 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/17 11:53:03 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_acc_for_d_2(int d, int how_numb, int *wid_acc)
{
	(d < 0) ? write(1, "-", 1) && how_numb-- : 1;
	while (wid_acc[1]-- > how_numb && write(1, "0", 1))
		wid_acc[3]++;
	(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
}

void		ft_wid_acc_for_d_3(int d, int how_numb, int *wid_acc, int tmp)
{
	(d < 0) ? write(1, "-", 1) && how_numb-- && wid_acc[0]-- : 1;
	while (tmp-- > how_numb && write(1, "0", 1))
		wid_acc[3]++;
	(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
		wid_acc[3]++;
}

void		ft_wid_acc_for_d(int d, int how_numb, int dsh_or_zr, int *wid_acc)
{
	int tmp;

	if (dsh_or_zr < 0)
	{
		tmp = wid_acc[1];
		wid_acc[3] += how_numb;
		if (wid_acc[0] <= wid_acc[1] && wid_acc[1] > how_numb)
			ft_wid_acc_for_d_2(d, how_numb, wid_acc);
		else if (wid_acc[0] > wid_acc[1] && wid_acc[1] > how_numb)
			ft_wid_acc_for_d_3(d, how_numb, wid_acc, tmp);
		else if (wid_acc[0] >= wid_acc[1] && wid_acc[1] < how_numb)
		{
			(d < 0) ? write(1, "-", 1) && how_numb-- && wid_acc[0]-- : 1;
			if (d == 0)
				write(1, " ", 1);
			else
				(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
			while (wid_acc[0]-- > how_numb && write(1, " ", 1))
				wid_acc[3]++;
		}
	}
	else if (dsh_or_zr >= 0)
		ft_wid_acc_for_d_1(d, how_numb, dsh_or_zr, wid_acc);
}

void		ft_spec_di(char *format, va_list ap, int dsh_zr, int *wid_acc)
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
		wid_acc[3] += how_numb;
		ft_putnbr(d);
	}
}
