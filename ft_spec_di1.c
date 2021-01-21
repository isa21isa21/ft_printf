/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:05:06 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:37:25 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_make_accuracy_for_d(int d, int how_numb, int *wid_or_accur)
{
	if (wid_or_accur[1] < how_numb)
	{
		if (d == 0)
			return ;
		ft_putnbr(d);
	}
	else if (wid_or_accur[1] >= how_numb)
	{
		if (d < 0 && d != -2147483648 && write(1, "-", 1) && how_numb--)
		{
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
	else
		ft_putnbr(d);
	wid_or_accur[3] += how_numb;
}

void		ft_wid_acc_for_d_1_1(int d, int num, int *dsh_zr, int *w_a)
{
	int tmp;

	tmp = w_a[1];
	if (dsh_zr[0] > dsh_zr[1])
	{
		(d < 0 && d != -2147483648) ? w_a[0]-- : 1;
		while (w_a[0]-- > w_a[1] && write(1, " ", 1))
			w_a[3]++;
		(d < 0 && d != -2147483648) ? write(1, "-", 1) && num-- && w_a[0]-- : 1;
		while (tmp-- > num && write(1, "0", 1))
			w_a[3]++;
		(d < 0 && d != -2147483648) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
	else
	{
		(d < 0 && d != -2147483648) ? w_a[0]-- : 1;
		while (w_a[0]-- > w_a[1] && write(1, " ", 1))
			w_a[3]++;
		(d < 0 && d != -2147483648) ? write(1, "-", 1) && num-- : 1;
		while (tmp-- > num && write(1, "0", 1))
			w_a[3]++;
		(d < 0 && d != -2147483648) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
}

void		ft_wid_acc_for_d_1_2(int d, int nb, int *w_a)
{
	while (w_a[0]-- > nb && write(1, " ", 1))
		w_a[3]++;
	(d < 0 && d != -2147483648) ? write(1, "-", 1) && nb-- && w_a[0]-- : 1;
	if (d == 0 && write(1, " ", 1))
		return ;
	(d < 0 && d != -2147483648) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
}

void		ft_wid_acc_for_d_1(int d, int nb, int *dsh_or_zr, int *w_a)
{
	int tmp;

	tmp = w_a[1];
	w_a[3] += nb;
	if (w_a[0] <= w_a[1] && w_a[1] >= nb)
	{
		(d < 0 && d != -2147483648) ? write(1, "-", 1) && nb-- : 1;
		while (w_a[1]-- > nb && write(1, "0", 1))
			w_a[3]++;
		(d < 0 && d != -2147483648) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
	else if (w_a[0] < w_a[1] && w_a[1] <= nb)
	{
		(d < 0 && d != -2147483648) ? write(1, "-", 1) && nb-- : 1;
		(d < 0) ? ft_putnbr(d * (-1)) : ft_putnbr(d);
	}
	else if (w_a[0] > w_a[1] && w_a[1] >= nb)
		ft_wid_acc_for_d_1_1(d, nb, dsh_or_zr, w_a);
	else if (w_a[0] >= w_a[1] && w_a[1] < nb)
		ft_wid_acc_for_d_1_2(d, nb, w_a);
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
