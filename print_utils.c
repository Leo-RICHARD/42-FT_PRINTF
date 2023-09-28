/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:52:58 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/25 17:30:04 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints(char *str, int len)
{
	if (!str)
		write(1, "(null)", len);
	else
		write(1, str, len);
}

void	ft_printn(int nb)
{
	char c;

	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	c = nb % 10 + 48;
	if (nb >= 10)
		ft_printn(nb / 10);
	write(1, &c, 1);
}

void	ft_printu(unsigned int nb)
{
	char c;

	c = nb % 10 + 48;
	if (nb >= 10)
		ft_printu(nb / 10);
	write(1, &c, 1);
}

void	ft_printhex(unsigned int nb, char *base)
{
	char c;

	c = base[nb % 16];
	if (nb >= 16)
		ft_printhex(nb / 16, base);
	write(1, &c, 1);
}

void	ft_printhexp(unsigned long int nb, char *base)
{
	char c;

	c = base[nb % 16];
	if (nb >= 16)
		ft_printhexp(nb / 16, base);
	write(1, &c, 1);
}
