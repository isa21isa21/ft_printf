/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:00:30 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/21 12:55:44 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit_zero(int c);
int		ft_isdigit(int c);
void	ft_putchar(char c);
void	ft_puthex(unsigned int x);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putuint(unsigned n);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		ft_puthex_num(unsigned long long int nb);
void	ft_putptr_var(int i, char *hex);
void	ft_putptr(unsigned long int x);
void	ft_puthex_up(unsigned int x);
int		how_nums_in_d(int d);
int		how_nums_in_uint(unsigned int u);
int		ft_how_nums_in_u(unsigned int n);
void	ft_wid_for_d(int d, int how_numb, int *dsh_or_zer, int *wid_acc);
void	ft_make_accuracy_for_d(int d, int how_numb, int *wid_or_accur);
void	ft_wid_acc_for_d_1(int d, int numb, int *dsh_or_zr, int *wid_acc);
void	ft_wid_acc_for_d_4(int d, int how_numb, int *wid_acc);
void	ft_make_dash_for_s(char *s, int len, int *wid_or_accur);
void	ft_make_non_dash_for_s_1(char *s, int len, int *wid_or_accur);
void	ft_make_non_dash_for_s_2(char *s, int len, int *wid_or_accur);
void	ft_spec_perc_one(char c, int *wid_acc);
void	ft_spec_perc(char *format, int *dash_zero, int *wid_acc);
void	ft_spec_c(va_list ap, int *dash_zero, int *wid_acc);
char	*ft_spec_s(char *format, va_list ap, int *dsh_zer, int *wid_acc);
void	ft_spec_p(char *format, va_list ap, int *dsh_zer, int *wid_acc);
void	ft_spec_di(char *format, va_list ap, int *dsh_zr, int *wid_acc);
void	ft_spec_u(char *format, va_list ap, int *dash_zr, int *wid_acc);
void	ft_spec_x(char *format, va_list ap, int *dsh_zr, int *wid_acc);
void	ft_spec_x_up(char *format, va_list ap, int *dsh_zr, int *wid_acc);
char	*ft_do_spec(char *format, va_list ap, int *dash_zero, int *wid_acc);
char	*ft_wid_or_acc_1(char *format, int *wid_or_acc, char *tmp);
void	ft_wid_for_d_1(int d, int how_numb, int *wid_or_accur);
void	ft_wid_for_d_2(int d, int how_numb, int *dsh_or_zer, int *wid_acc);
void	ft_wid_acc_u_3(unsigned int u, int how_numb, int *wid_acc, int tmp);
void	ft_wid_acc_u_2(unsigned int u, int how_numb, int *wid_acc);
void	ft_wid_acc_u_1(unsigned int u, int numb, int *dsh_zr, int *wid_acc);
void	ft_wid_acc_u_1_1(unsigned u, int numb, int *wid_acc);
void	ft_wid_for_u_2(unsigned d, int how_numb, int *wid_acc);

#endif
