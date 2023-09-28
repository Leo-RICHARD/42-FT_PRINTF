/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:10:47 by lrichard          #+#    #+#             */
/*   Updated: 2021/02/25 17:36:20 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (6);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlenc(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '%')
			return (i);
	return (i);
}

int	ft_atoi(char **nptr)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while ((*nptr)[i] > 47 && (*nptr)[i] < 58)
	{
		nb = nb * 10 + (*nptr)[i] - 48;
		i++;
	}
	*nptr += i;
	return (nb);
}

int	ft_count(char type, void *var)
{
	int				count;
	unsigned int	base;

	base = 10;
	count = (type != 'p') ? 1 : 3;
	if (type == 's')
		return (ft_strlen(*(char **)var));
	if (type == 'i' || type == 'u' || type == 'x' || type == 'X' || type == 'p')
	{
		if (type == 'i' && *(int *)var == -2147483648)
			return (10);
		if (type == 'i' && *(int*)var < 0)
			*(int*)var = -*(int*)var;
		if (type != 'i' && type != 'u')
			base = 16;
		while (type != 'p' && (*(unsigned int *)var /= base))
			count++;
		while (type == 'p' && (*(unsigned long int *)var /= base))
			count++;
	}
	return (count);
}

int	ft_countchars(char type, void *var)
{
	int					i;
	unsigned int		u;
	unsigned long int	p;
	void				*ptr;

	ptr = var;
	if (type == 'i')
	{
		i = *(int *)var;
		ptr = &i;
	}
	else if (type == 'p')
	{
		p = *(unsigned long int *)var;
		ptr = &p;
	}
	else if (type == 'u' || type == 'x' || type == 'X')
	{
		u = *(unsigned int *)var;
		ptr = &u;
	}
	return (ft_count(type, ptr));
}
