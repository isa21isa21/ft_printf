/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:06:38 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:52:35 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_for_u_1(unsigned d, int numb, int *wid_acc)
{
	if (wid_acc[2] > 0)
		while (wid_acc[0]-- != numb && write(1, " ", 1))
			wid_acc[3]++;
	else if (wid_acc[2] == 0)
	{
		if (wid_acc[0] < numb)
		{
			ft_putuint(d);
			return ;
		}
		else
			while (wid_acc[0]-- != numb && write(1, "0", 1))
				wid_acc[3]++;
	}
	ft_putuint(d);
}

void		ft_wid_for_u(unsigned d, int numb, int *dsh_zr, int *wid_acc)
{
	wid_acc[3] += numb;
	if (dsh_zr[0] > 0)
		ft_wid_for_u_2(d, numb, wid_acc);
	else if (dsh_zr[1] > 0)
	{
		if (wid_acc[2] > 0)
			while (wid_acc[0]-- != numb && write(1, " ", 1))
				wid_acc[3]++;
		else if (wid_acc[2] == 0)
			ft_wid_for_u_1(d, numb, wid_acc);
	}
	else
	{
		while (wid_acc[0]-- > numb && write(1, " ", 1))
			wid_acc[3]++;
		if (d == 0 && wid_acc[2] > 0)
		{
			write(1, " ", 1);
			wid_acc[3]++;
			return ;
		}
		ft_putuint(d);
	}
}

void		ft_make_acc_for_u(char *format, unsigned d, int numb, int *wid_acc)
{
	if (wid_acc[1] <= numb)
	{
		if (d == 0 && !ft_isdigit_zero(*(format - 1)) && *(format - 1) != '*')
			return ;
		else if (d == 0 && *(format - 1) == '*' && wid_acc[1] == 0)
			return ;
		ft_putuint(d);
	}
	else if (wid_acc[1] > numb)
	{
		if (d < 0 && write(1, "-", 1))
		{
			while (wid_acc[1]-- > numb && write(1, "0", 1))
				wid_acc[3]++;
			ft_putuint(d * (-1));
			wid_acc[3]++;
		}
		else if (d >= 0)
		{
			while (wid_acc[1]-- > numb && write(1, "0", 1))
				wid_acc[3]++;
			ft_putuint(d);
		}
	}
	wid_acc[3] += numb;
}

void		ft_wid_acc_u(unsigned u, int numb, int *dsh_zr, int *wid_acc)
{
	int tmp;

	if (dsh_zr[0] > 0)
	{
		tmp = wid_acc[1];
		wid_acc[3] += numb;
		if (wid_acc[0] <= wid_acc[1] && wid_acc[1] >= numb)
		{
			(u < 0) ? write(1, "-", 1) && numb-- : 1;
			while (wid_acc[1]-- > numb && write(1, "0", 1))
				wid_acc[3]++;
			(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
		}
		else if (wid_acc[0] > wid_acc[1] && wid_acc[1] >= numb)
			ft_wid_acc_u_3(u, numb, wid_acc, tmp);
		else if (wid_acc[0] <= wid_acc[1] && wid_acc[1] <= numb)
			ft_putuint(u);
		else if (wid_acc[0] >= wid_acc[1] && wid_acc[1] < numb)
			ft_wid_acc_u_2(u, numb, wid_acc);
	}
	else if (dsh_zr[1] > 0 || (dsh_zr[0] == 0 && dsh_zr[1] == 0))
		ft_wid_acc_u_1(u, numb, dsh_zr, wid_acc);
}

void		ft_spec_u(char *format, va_list ap, int *dash_zr, int *wid_acc)
{
	unsigned		u;
	int				how_numb;

	u = va_arg(ap, int);
	how_numb = ft_how_nums_in_u(u);
	if (u == 0 && (*(format - 1) == '.' && !ft_isdigit(*(format - 2))))
		return ;
	if (wid_acc[0] > 0 && wid_acc[1] < 0)
		ft_wid_for_u(u, how_numb, dash_zr, wid_acc);
	else if (wid_acc[0] < 1 && wid_acc[1] > -1)
		ft_make_acc_for_u(format, u, how_numb, wid_acc);
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
