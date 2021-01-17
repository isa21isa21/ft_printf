/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:21:36 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/17 11:42:43 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_for_d_1(int d, int how_numb, int *wid_or_accur)
{
	if (wid_or_accur[2] > 0)
		while (wid_or_accur[0]-- != how_numb && write(1, " ", 1))
			wid_or_accur[3]++;
	else if (wid_or_accur[2] == 0)
	{
		if (d < 0)
		{
			write(1, "-", 1);
			while (wid_or_accur[0]-- > how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
			ft_putnbr(d * (-1));
		}
		else
		{
			while (wid_or_accur[0]-- != how_numb && write(1, "0", 1))
				wid_or_accur[3]++;
			ft_putnbr(d);
		}
	}
	wid_or_accur[3] += how_numb;
}

void		ft_wid_for_d_2(int d, int how_numb, int *wid_or_accur)
{
	if (wid_or_accur[0] < how_numb)
		ft_putnbr(d);
	else
	{
		while (wid_or_accur[0]-- != how_numb && write(1, " ", 1))
			wid_or_accur[3]++;
		if (d == 0 && wid_or_accur[2] > 0)
		{
			write(1, " ", 1);
			wid_or_accur[3]++;
			return ;
		}
		ft_putnbr(d);
	}
	wid_or_accur[3] += how_numb;
}
