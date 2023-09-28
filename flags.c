/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:56:56 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/25 17:32:38 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_arg(t_args *args)
{
	if (args->type == '%')
		args->c = '%';
	else if (args->type == 'c')
		args->c = va_arg(args->vargs, int);
	else if (args->type == 's')
		args->s = va_arg(args->vargs, char *);
	else if (args->type == 'p')
		args->p = va_arg(args->vargs, unsigned long int);
	else if (args->type == 'i')
		args->i = va_arg(args->vargs, int);
	else if (args->type == 'u' || args->type == 'x' || args->type == 'X')
		args->u = va_arg(args->vargs, unsigned int);
	if (args->type == 'c' || args->type == '%')
		args->var = &(args->c);
	else if (args->type == 's')
		args->var = &(args->s);
	else if (args->type == 'i')
		args->var = &(args->i);
	else if (args->type == 'u' || args->type == 'x' || args->type == 'X')
		args->var = &(args->u);
	else if (args->type == 'p')
		args->var = &(args->p);
}

void	ft_deal_with_zero(t_flags *flags, t_args *args)
{
	if (flags->zero && (flags->minus || args->type == 'c' \
									|| args->type == 'p' || args->type == 's'))
		flags->zero = 0;
	else if (flags->zero && flags->precision > -1)
		flags->zero = 0;
	if (flags->zero)
	{
		flags->precision = flags->width;
		flags->width = 0;
	}
}

void	ft_process_flags(t_flags *flags, t_args *args)
{
	args->len = ft_countchars(args->type, args->var);
	ft_deal_with_zero(flags, args);
	if (flags->precision >= 0 && flags->precision <= args->len)
	{
		if (args->type == 's')
			args->len = flags->precision;
		if (flags->precision)
			flags->precision = -1;
	}
	else if (flags->precision > 0 && args->type != 's')
	{
		flags->precision -= args->len;
		if (flags->zero && args->type == 'i' && *(int *)args->var < 0)
			flags->precision--;
		flags->width -= flags->precision;
	}
	args->isnull = (!flags->zero && \
					!flags->precision && ft_isnull(args->type, args->var));
	if (!args->isnull)
		flags->width -= args->len;
	if (args->type == 'i' && *(int *)args->var < 0)
		flags->width--;
	if (flags->width < 0)
		flags->width = 0;
}

void	ft_parse_flags(char **str, t_flags *flags, t_args *args)
{
	while (**str)
	{
		if (**str == '0')
			ft_zero(str, flags);
		if (**str == '-')
			ft_minus(str, flags);
		if (**str == '.')
			ft_get_precision(str, flags, args);
		if ((**str >= '0' && **str <= '9') || **str == '*')
			ft_get_width(str, flags, args);
		if ((**str >= 'c' && **str <= 'x') || **str == 'X' || **str == '%')
		{
			args->type = **str;
			if (**str == 'd')
				args->type = 'i';
			(*str)++;
			return ;
		}
	}
}
