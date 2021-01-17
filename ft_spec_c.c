/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:01:25 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/09 12:52:54 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_c_one(char c, int *wid_acc)
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

void		ft_spec_c(va_list ap, int dash_zero, int *wid_acc)
{
	char c;

	c = va_arg(ap, int);
	if (dash_zero < 0)
		ft_spec_c_one(c, wid_acc);
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
