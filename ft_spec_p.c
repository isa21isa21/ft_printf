/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:03:35 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/15 16:50:17 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_p_1(unsigned long x, int how_numb, int dsh_zr, int *wid_acc)
{
	if (dsh_zr < 0)
	{
		ft_putptr(x);
		while (wid_acc[0]-- > how_numb && write(1, " ", 1))
			wid_acc[3]++;
		wid_acc[3] += how_numb;
	}
	else if (dsh_zr == 0)
	{
		if (x == 0 && wid_acc[2] > 0)
			(x == 0) ? how_numb-- : 1;
		while (wid_acc[0]-- > how_numb && write(1, " ", 1))
			wid_acc[3]++;
		wid_acc[3] += how_numb;
		if (x == 0 && wid_acc[2] > 0)
			ft_putstr("0x");
		else
			ft_putptr(x);
	}
}

void		ft_spec_p(char *format, va_list ap, int dsh_zer, int *wid_acc)
{
	unsigned long	p;
	int				how_numb;

	how_numb = 0;
	p = va_arg(ap, unsigned long);
	if ((void*)p == NULL)
		how_numb++;
	how_numb += (ft_puthex_num(p) + 2);
	if (p == 0 && (*(format - 1) == '.' && !ft_isdigit(*(format - 2))))
	{
		wid_acc[3] += how_numb - 1;
		ft_putstr("0x");
		return ;
	}
	if (wid_acc[0] > 0 && wid_acc[1] < 0)
		ft_spec_p_1(p, how_numb, dsh_zer, wid_acc);
	else
	{
		ft_putptr(p);
		wid_acc[3] += how_numb;
	}
}
