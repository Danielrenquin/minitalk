/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:29:05 by drenquin          #+#    #+#             */
/*   Updated: 2024/06/03 17:51:09 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		ap;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			write(1, "%", 1);
			str++;
		}
		else if (*str == '%')
			count += ft_cspdiux(*(++str), ap);
		else
			write(1, str, 1);
		str++;
		count++;
	}
	va_end(ap);
	return (count);
}
