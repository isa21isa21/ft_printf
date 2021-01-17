/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:03:27 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/17 11:54:01 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_perc_1(char c, int *wid_acc)
{
	if (wid_acc[0] > 0)
	{
		ft_putchar(c);
		while (wid_acc[0]-- > 1 && write(1, " ", 1))
			wid_acc[3]++;
		wid_acc[3] += 1;
	}
	else
	{
		ft_putchar(c);
		wid_acc[3] += 1;
	}
}

void		ft_spec_perc_2(char c, int *wid_acc)
{
	if (wid_acc[0] > 0)
	{
		while (wid_acc[0]-- > 1 && write(1, "0", 1))
			wid_acc[3]++;
		wid_acc[3]++;
		ft_putchar(c);
	}
}

void		ft_spec_perc(char *format, int dash_zero, int *wid_acc)
{
	char c;

	c = *format;
	if (dash_zero < 0)
		ft_spec_perc_1(c, wid_acc);
	else if (dash_zero > 0)
		ft_spec_perc_2(c, wid_acc);
	else if (wid_acc[0] > 0)
	{
		while (wid_acc[0]-- > 1 && write(1, " ", 1))
			wid_acc[3]++;
		ft_putchar(c);
		wid_acc[3] += 1;
	}
	else
	{
		ft_putchar(c);
		wid_acc[3] += 1;
	}
}
