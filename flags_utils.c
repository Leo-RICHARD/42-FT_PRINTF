/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:57:06 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/25 17:29:30 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero(char **str, t_flags *flags)
{
	flags->zero = 1;
	while (**str == '0')
		(*str)++;
}

void	ft_minus(char **str, t_flags *flags)
{
	flags->minus = 1;
	while (**str == '-')
		(*str)++;
}

void	ft_get_precision(char **str, t_flags *flags, t_args *args)
{
	int	wildcard;

	(*str)++;
	flags->precision = 0;
	if (**str == '*')
	{
		wildcard = va_arg(args->vargs, int);
		if (wildcard >= 0)
			flags->precision = wildcard;
		else
			flags->precision = -1;
		(*str)++;
		return ;
	}
	else if (**str >= '0' && **str <= '9')
		flags->precision = ft_atoi(str);
}

void	ft_get_width(char **str, t_flags *flags, t_args *args)
{
	int wildcard;

	if (**str == '*')
	{
		wildcard = va_arg(args->vargs, int);
		if (wildcard > 0)
			flags->width = wildcard;
		else
		{
			ft_minus(str, flags);
			flags->width = -wildcard;
		}
		(*str)++;
		return ;
	}
	flags->width = ft_atoi(str);
}

int		ft_isnull(char type, void *var)
{
	if (type == 'c' || type == '%')
		return (0);
	if (type == 'i')
		return ((*(int *)var == 0));
	if (type == 'u' || type == 'x' || type == 'X')
		return ((*(unsigned int *)var == 0));
	if (type == 'p')
		return ((*(int *)var == 0));
	return (0);
}
