/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:51:44 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/25 17:31:12 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_till_flag(char **str, t_args *args)
{
	int len;

	len = ft_strlenc(*str);
	write(1, *str, len);
	args->printed += len;
	if (!(*str)[len])
		len--;
	*str += len + 1;
}

void	ft_print_var(t_args *args)
{
	if (args->type == 'c' || args->type == '%')
		write(1, &*(char *)args->var, 1);
	else if (args->type == 'i')
		ft_printn(*(int *)args->var);
	else if (args->type == 'u')
		ft_printu(*(unsigned int *)args->var);
	else if (args->type == 's')
		ft_prints(*(char **)args->var, args->len);
	else if (args->type == 'x')
		ft_printhex(*(unsigned int *)args->var, "0123456789abcdef");
	else if (args->type == 'X')
		ft_printhex(*(unsigned int *)args->var, "0123456789ABCDEF");
	else if (args->type == 'p')
		ft_printhexp(*(unsigned long int *)args->var, "0123456789abcdef");
	args->printed += args->len;
}

void	ft_print_zeros_and_spaces(char c, int number)
{
	int n;

	n = number / 2;
	if (number % 2)
		write(1, &c, 1);
	if (n && c == ' ')
		while (n--)
			write(1, "  ", 2);
	else if (n)
		while (n--)
			write(1, "00", 2);
}

void	ft_print_arg(t_args *args, t_flags *flags)
{
	if (flags->width > 0 && !(flags->minus))
		ft_print_zeros_and_spaces(' ', flags->width);
	if (args->type == 'p')
		write(1, "0x", 2);
	if (args->type == 'i' && *(int *)args->var < 0)
	{
		write(1, "-", 1);
		args->printed++;
	}
	if (args->type != 's' && flags->precision > 0)
	{
		ft_print_zeros_and_spaces('0', flags->precision);
		args->printed += flags->precision;
	}
	if (!args->isnull)
		ft_print_var(args);
	args->printed += flags->width;
	if (flags->width > 0 && flags->minus)
		ft_print_zeros_and_spaces(' ', flags->width);
}
