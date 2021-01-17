/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:26:20 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/14 14:50:03 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_puthex(unsigned int x)
{
	char	hex[16];
	int		tmp;
	int		i;

	ft_bzero(hex, 16);
	i = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (x)
	{
		tmp = x % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('A' - 10) : '0'));
		x /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putptr_var(i, hex);
		i--;
	}
}
