/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:21:36 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:37:22 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_for_d(int d, int how_numb, int *dsh_or_zer, int *wid_acc)
{
	if (dsh_or_zer[0] > dsh_or_zer[1])
	{
		if (d == 0 && wid_acc[2] > 0)
			write(1, " ", 1);
		else
			ft_putnbr(d);
		while (wid_acc[0]-- > how_numb && write(1, " ", 1))
			wid_acc[3]++;
		wid_acc[3] += how_numb;
	}
	else if (dsh_or_zer[1] > dsh_or_zer[0])
		ft_wid_for_d_1(d, how_numb, wid_acc);
	else
		ft_wid_for_d_2(d, how_numb, dsh_or_zer, wid_acc);
}

void		ft_wid_for_d_1(int d, int how_numb, int *wid_or_accur)
{
	if (wid_or_accur[2] > 0)
		while (wid_or_accur[0]-- != how_numb && write(1, " ", 1))
			wid_or_accur[3]++;
	else if (wid_or_accur[2] == 0)
	{
		if (d < 0 && d != -2147483648)
		{
			write(1, "-", 1);
			while (wid_or_accur[0]-- > how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
			ft_putnbr(d * (-1));
		}
		else
		{
			if (wid_or_accur[0] < how_numb)
				ft_putnbr(d);
			else
			{
				while (wid_or_accur[0]-- != how_numb && write(1, "0", 1))
					wid_or_accur[3]++;
				ft_putnbr(d);
			}
		}
	}
	wid_or_accur[3] += how_numb;
}

void		ft_wid_for_d_2(int d, int how_numb, int *dsh_or_zer, int *wid_acc)
{
	if (wid_acc[0] < how_numb)
		ft_putnbr(d);
	else
	{
		if (dsh_or_zer[0] > 0 && dsh_or_zer[1] > 0)
		{
			ft_putnbr(d);
			while (wid_acc[0]-- != how_numb && write(1, " ", 1))
				wid_acc[3]++;
		}
		else
		{
			while (wid_acc[0]-- != how_numb && write(1, " ", 1))
				wid_acc[3]++;
			if (d == 0 && wid_acc[2] > 0)
			{
				write(1, " ", 1);
				wid_acc[3]++;
				return ;
			}
			ft_putnbr(d);
		}
	}
	wid_acc[3] += how_numb;
}
