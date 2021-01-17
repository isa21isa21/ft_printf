/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:25:38 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/09 13:01:49 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	long int c;
	long int i;
	long int znak;

	znak = 1;
	i = 0;
	c = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			znak *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + str[i] - '0';
		i++;
	}
	return (c * znak);
}
