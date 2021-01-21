/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:08:08 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:54:03 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_x_up_1(unsigned long x, int num, int *dsh_zr, int *wid_acc)
{
	wid_acc[3] += num;
	if (dsh_zr[0] > 0)
	{
		if (x == 0 && wid_acc[2] > 0)
			write(1, " ", 1);
		else
			ft_puthex_up(x);
		while (wid_acc[0]-- > num && write(1, " ", 1))
			wid_acc[3]++;
	}
	else if (dsh_zr[1] > 0)
	{
		while (wid_acc[0]-- > num && write(1, "0", 1))
			wid_acc[3]++;
		ft_puthex_up(x);
	}
	else if (dsh_zr[0] == 0 && dsh_zr[1] == 0)
	{
		while (wid_acc[0]-- > num && write(1, " ", 1))
			wid_acc[3]++;
		if (x == 0 && wid_acc[2] > 0 && write(1, " ", 1))
			return ;
		ft_puthex_up(x);
	}
}

void		ft_spec_x_up_2(char *format, unsigned long x, int num, int *wid_acc)
{
	if (wid_acc[1] <= num)
	{
		if (x == 0 && *(format - 1) == '*' && wid_acc[1] == 0)
			return ;
		else if (x == 0 && *(format - 1) == '0')
			return ;
		ft_puthex_up(x);
		wid_acc[3] += num;
	}
	else if (wid_acc[1] > num)
	{
		while (wid_acc[1]-- > num && write(1, "0", 1))
			wid_acc[3]++;
		ft_puthex_up(x);
		wid_acc[3] += num;
	}
}

void		ft_spec_x_up_4(unsigned long x, int num, int *wid_acc, int tmp)
{
	if (wid_acc[1] >= num)
	{
		while (wid_acc[1]-- > num && write(1, "0", 1))
			wid_acc[3]++;
		ft_puthex_up(x);
		while (wid_acc[0]-- > tmp && write(1, " ", 1))
			wid_acc[3]++;
	}
	else if (wid_acc[1] < num)
	{
		if (x == 0)
			write(1, " ", 1);
		else
			ft_puthex_up(x);
		while (wid_acc[0]-- > num && write(1, " ", 1))
			wid_acc[3]++;
	}
}

void		ft_spec_x_up_3(unsigned long x, int num, int *dsh_zr, int *wid_acc)
{
	int tmp;

	tmp = wid_acc[1];
	wid_acc[3] += num;
	if (dsh_zr[0] > 0)
		ft_spec_x_up_4(x, num, wid_acc, tmp);
	else if (dsh_zr[1] > 0 || (dsh_zr[0] == 0 && dsh_zr[1] == 0))
	{
		if (wid_acc[1] >= num)
		{
			while (wid_acc[0]-- > wid_acc[1] && write(1, " ", 1))
				wid_acc[3]++;
			while (wid_acc[1]-- > num && write(1, "0", 1))
				wid_acc[3]++;
		}
		else if (wid_acc[1] < num)
		{
			while (wid_acc[0]-- > num && write(1, " ", 1))
				wid_acc[3]++;
			if (x == 0 && write(1, " ", 1))
				return ;
		}
		ft_puthex_up(x);
	}
}

void		ft_spec_x_up(char *format, va_list ap, int *dsh_zr, int *wid_acc)
{
	unsigned int	x;
	int				how_numb;

	x = va_arg(ap, unsigned int);
	how_numb = ft_puthex_num(x);
	if (x <= 0)
		how_numb++;
	if (x == 0 && (*(format - 1) == '.' && !ft_isdigit(*(format - 2))))
		return ;
	if (wid_acc[0] > 0 && wid_acc[1] < 0)
		ft_spec_x_up_1(x, how_numb, dsh_zr, wid_acc);
	else if (wid_acc[0] < 1 && wid_acc[1] > -1)
		ft_spec_x_up_2(format, x, how_numb, wid_acc);
	else if (wid_acc[0] > 0 && wid_acc[1] > -1)
		ft_spec_x_up_3(x, how_numb, dsh_zr, wid_acc);
	else
	{
		ft_puthex_up(x);
		wid_acc[3] += how_numb;
	}
}
