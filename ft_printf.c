/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:33:27 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/25 17:27:45 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->zero = 0;
	flags->minus = 0;
}

int		ft_printf(const char *str, ...)
{
	t_args	args;
	t_flags	flags;
	char	*s;

	s = (char *)str;
	args.printed = 0;
	if (str)
	{
		va_start(args.vargs, str);
		while (*s)
		{
			ft_init_struct(&flags);
			ft_print_till_flag(&s, &args);
			if (*s)
			{
				ft_parse_flags(&s, &flags, &args);
				ft_get_arg(&args);
				ft_process_flags(&flags, &args);
				ft_print_arg(&args, &flags);
			}
		}
		va_end(args.vargs);
	}
	return (args.printed);
}
