/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:00:40 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:47:14 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_acc_u_4(unsigned u, int numb, int *wid_acc)
{
	int tmp;

	tmp = wid_acc[1];
	(u < 0) ? wid_acc[0]-- : 1;
	while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
		wid_acc[3]++;
	(u < 0) ? write(1, "-", 1) && numb-- && wid_acc[0]-- : 1;
	while (tmp-- > numb && write(1, "0", 1))
		wid_acc[3]++;
	(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
}

void		ft_wid_acc_u_5(unsigned u, int numb, int *wid_acc)
{
	int tmp;

	tmp = wid_acc[1];
	(u < 0) ? wid_acc[0]-- : 1;
	while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
		wid_acc[3]++;
	(u < 0) ? write(1, "-", 1) && numb-- : 1;
	while (tmp-- > numb && write(1, "0", 1))
		wid_acc[3]++;
	(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
}

void		ft_wid_acc_u_1(unsigned u, int numb, int *dsh_zr, int *wid_acc)
{
	wid_acc[3] += numb;
	if (wid_acc[0] <= wid_acc[1] && wid_acc[1] >= numb)
	{
		(u < 0) ? write(1, "-", 1) && numb-- : 1;
		while (wid_acc[1]-- > numb && write(1, "0", 1))
			wid_acc[3]++;
		(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
	}
	else if (wid_acc[0] > wid_acc[1] && wid_acc[1] >= numb)
	{
		if (dsh_zr[1] > 0)
			ft_wid_acc_u_4(u, numb, wid_acc);
		else
			ft_wid_acc_u_5(u, numb, wid_acc);
	}
	else if (wid_acc[0] < wid_acc[1] && wid_acc[1] <= numb)
	{
		(u < 0) ? write(1, "-", 1) && numb-- : 1;
		(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
	}
	else if (wid_acc[0] >= wid_acc[1] && wid_acc[1] < numb)
		ft_wid_acc_u_1_1(u, numb, wid_acc);
}

void		ft_wid_acc_u_2(unsigned u, int how_numb, int *wid_acc)
{
	(u < 0) ? write(1, "-", 1) && how_numb-- && wid_acc[0]-- : 1;
	if (u == 0)
		write(1, " ", 1);
	else
		(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
	while (wid_acc[0]-- > how_numb && write(1, " ", 1))
		wid_acc[3]++;
}

void		ft_wid_acc_u_3(unsigned u, int how_numb, int *wid_acc, int tmp)
{
	(u < 0) ? write(1, "-", 1) && how_numb-- && wid_acc[0]-- : 1;
	while (tmp-- > how_numb && write(1, "0", 1))
		wid_acc[3]++;
	(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
	while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
		wid_acc[3]++;
}
