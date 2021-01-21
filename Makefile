# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/09 10:44:57 by cquickbe          #+#    #+#              #
#    Updated: 2021/01/21 12:43:15 by cquickbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = libftprintf.a
src = ft_funcs1.c ft_funcs2.c \
		ft_spec_perc.c ft_spec_c.c \
		ft_spec_di0.c ft_spec_di1.c \
		ft_spec_di2.c ft_spec_p.c \
		ft_spec_s1.c ft_spec_s2.c \
		ft_spec_u0.c ft_spec_u1.c \
		ft_spec_u2.c \
		ft_spec_x_up.c ft_spec_x.c \
		ft_printf.c ft_atoi.c \
		ft_bzero.c ft_isdigit.c \
		ft_isdigit_zero.c \
		ft_putchar.c ft_putstr.c \
		ft_putnbr.c ft_puthex.c \
		ft_putuint.c ft_strlen.c 
lib = ft_printf.h
obj = ${src:.c=.o}
flags = -Wall -Wextra -Werror
all:	${name}
${name}:	${obj}
	ar rc ${name} ${obj}
	ranlib ${name}
.c.o:
	gcc ${flags} -I/${lib} -c $< -o ${<:.c=.o}
clean:
	rm -f ${obj} ${obj_b}
fclean: clean
	rm -f ${name}
re: fclean all
