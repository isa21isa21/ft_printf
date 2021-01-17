/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:33:45 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/16 12:56:12 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthex_num(unsigned long long int nb)
{
	char	hex[16];
	int		tmp;
	int		i;
	int		b;

	ft_bzero(hex, 16);
	i = 0;
	b = 0;
	while (nb)
	{
		tmp = nb % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('A' - 10) : '0'));
		nb /= 16;
		i++;
	}
	while (i >= 0)
	{
		b++;
		i--;
	}
	return (b - 1);
}

void	ft_putptr_var(int i, char *hex)
{
	if (hex[i] == 'A')
		ft_putchar(hex[i] + 32);
	else if (hex[i] == 'B')
		ft_putchar(hex[i] + 32);
	else if (hex[i] == 'C')
		ft_putchar(hex[i] + 32);
	else if (hex[i] == 'D')
		ft_putchar(hex[i] + 32);
	else if (hex[i] == 'E')
		ft_putchar(hex[i] + 32);
	else if (hex[i] == 'F')
		ft_putchar(hex[i] + 32);
	else
		ft_putchar(hex[i]);
}

void	ft_putptr(unsigned long p)
{
	char	hex[16];
	int		tmp;
	int		i;

	ft_bzero(hex, 16);
	i = 0;
	ft_putstr("0x");
	if (p == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (p)
	{
		tmp = p % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('A' - 10) : '0'));
		p /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putptr_var(i, hex);
		i--;
	}
}

void	ft_puthex_up(unsigned int x)
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
		ft_putchar(hex[i]);
		i--;
	}
}

int		how_nums_in_d(int d)
{
	int i;

	i = 0;
	while (d)
	{
		i++;
		d = d / 10;
	}
	return (i);
}
