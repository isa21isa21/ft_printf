/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:43:40 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:52:28 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wid_for_u_2(unsigned d, int how_numb, int *wid_acc)
{
	if (d == 0 && wid_acc[2] > 0)
		write(1, " ", 1);
	else
		ft_putuint(d);
	if (d < 0)
		how_numb++;
	while (wid_acc[0]-- > how_numb && write(1, " ", 1))
		wid_acc[3]++;
}

void		ft_wid_acc_u_1_1(unsigned u, int numb, int *wid_acc)
{
	while (wid_acc[0]-- > numb && write(1, " ", 1))
		wid_acc[3]++;
	(u < 0) ? write(1, "-", 1) && numb-- && wid_acc[0]-- : 1;
	if (u == 0 && write(1, " ", 1))
		return ;
	(u < 0) ? ft_putuint(u * (-1)) : ft_putuint(u);
}
