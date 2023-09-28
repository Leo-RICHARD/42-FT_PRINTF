/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:34:48 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/25 17:28:55 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_args
{
	va_list				vargs;
	char				type;
	void				*var;
	char				c;
	char				*s;
	int					i;
	unsigned long int	u;
	unsigned long int	p;
	int					len;
	int					isnull;
	int					printed;
}						t_args;

typedef struct			s_flags
{
	int					width;
	int					precision;
	char				zero;
	char				minus;
}						t_flags;

int						ft_printf(const char *str, ...);
void					ft_prints(char *str, int len);
void					ft_printn(int nb);
void					ft_printu(unsigned int nb);
void					ft_printhex(unsigned int nb, char *base);
void					ft_printhexp(unsigned long int nb, char *base);
void					ft_print_till_flag(char **str, t_args *args);
void					ft_zero(char **str, t_flags *flags);
void					ft_minus(char **str, t_flags *flags);
void					ft_get_precision(char **str, t_flags *flags, \
																t_args *args);
void					ft_get_width(char **str, t_flags *flags, t_args *args);
int						ft_countchars(char type, void *var);
void					ft_parse_flags(char **str, t_flags *flags, \
																t_args *args);
void					ft_process_flags(t_flags *flags, t_args *args);
void					ft_get_arg(t_args *args);
void					ft_print_arg(t_args *args, t_flags *flags);
int						ft_strlen(char *str);
int						ft_strlenc(char *str);
int						ft_atoi(char **nptr);
int						ft_isnull(char type, void *var);

#endif
