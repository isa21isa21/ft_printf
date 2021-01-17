/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:05:06 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/17 11:42:41 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_for_d(int d, int how_numb, int dsh_or_zer, int *wid_or_accur)
{
	if (dsh_or_zer < 0)
	{
		if (d == 0 && wid_or_accur[2] > 0)
			write(1, " ", 1);
		else
			ft_putnbr(d);
		while (wid_or_accur[0]-- > how_numb && write(1, " ", 1))
			wid_or_accur[3]++;
		wid_or_accur[3] += how_numb;
	}
	else if (dsh_or_zer > 0)
		ft_wid_for_d_1(d, how_numb, wid_or_accur);
	else
		ft_wid_for_d_2(d, how_numb, wid_or_accur);
}

void		ft_make_accuracy_for_d(int d, int how_numb, int *wid_or_accur)
{
	if (wid_or_accur[1] <= how_numb)
	{
		if (d == 0)
			return ;
		ft_putnbr(d);
	}
	else if (wid_or_accur[1] > how_numb)
	{
		if (d < 0 && write(1, "-", 1))
		{
			how_numb--;
			while (wid_or_accur[1]-- > how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
			ft_putnbr(d * (-1));
			wid_or_accur[3]++;
		}
		else if (d >= 0)
		{
			while (wid_or_accur[1]-- > how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
			ft_putnbr(d);
		}
	}
	wid_or_accur[3] += how_numb;
}

void		ft_wid_acc_for_d_1_1(int d, int how_numb, int dsh_zr, int *wid_acc)
{
	int tmp;

	tmp = wid_acc[1];
	if (dsh_zr > 0)
	{
		(d < 0) ? wid_acc[0]-- : 1;
		while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
			wid_acc[3]++;
		(d < 0) ? write(1, "-", 1) && how_numb-- && wid_acc[0]-- : 1;
		while (tmp-- > how_numb && write(1, "0", 1))
			wid_acc[3]++;
		(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
	else
	{
		(d < 0) ? wid_acc[0]-- : 1;
		while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
			wid_acc[3]++;
		(d < 0) ? write(1, "-", 1) && how_numb-- : 1;
		while (tmp-- > how_numb && write(1, "0", 1))
			wid_acc[3]++;
		(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
}

void		ft_wid_acc_for_d_1(int d, int how_numb, int dsh_or_zr, int *wid_acc)
{
	int tmp;

	tmp = wid_acc[1];
	wid_acc[3] += how_numb;
	if (wid_acc[0] <= wid_acc[1] && wid_acc[1] > how_numb)
	{
		(d < 0) ? write(1, "-", 1) && how_numb-- : 1;
		while (wid_acc[1]-- > how_numb && write(1, "0", 1))
			wid_acc[3]++;
		(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
	else if (wid_acc[0] > wid_acc[1] && wid_acc[1] >= how_numb)
		ft_wid_acc_for_d_1_1(d, how_numb, dsh_or_zr, wid_acc);
	else if (wid_acc[0] >= wid_acc[1] && wid_acc[1] < how_numb)
	{
		while (wid_acc[0]-- > how_numb && write(1, " ", 1))
			wid_acc[3]++;
		(d < 0) ? write(1, "-", 1) && how_numb-- && wid_acc[0]-- : 1;
		if (d == 0 && write(1, " ", 1))
			return ;
		(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
}

void		ft_wid_acc_for_d_4(int d, int how_numb, int *wid_acc)
{
	int tmp;

	tmp = wid_acc[1];
	write(1, "-", 1);
	how_numb--;
	if (wid_acc[1] > how_numb)
		while (wid_acc[1]-- > how_numb && write(1, "0", 1))
			wid_acc[3]++;
	else if (wid_acc[1] > wid_acc[0] && wid_acc[1] > how_numb)
	{
		while (wid_acc[1]-- > how_numb && write(1, "0", 1))
			wid_acc[3]++;
	}
	ft_putnbr(d * -1);
	if (wid_acc[0] <= wid_acc[1])
	{
		while (wid_acc[0]-- > how_numb && write(1, " ", 1))
			wid_acc[3]++;
	}
	wid_acc[0]--;
}
