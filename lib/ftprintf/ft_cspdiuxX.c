/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspdiuxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:31:48 by drenquin          #+#    #+#             */
/*   Updated: 2024/03/27 23:51:45 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_cspdiux(char percent, va_list ap)
{
	int	count;

	count = 0;
	if (percent == 'c')
		ft_putchar(va_arg(ap, int));
	else if (percent == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (percent == 'd' || percent == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (percent == 'u')
		count += ft_unsigned(va_arg(ap, unsigned int));
	else if (percent == 'x')
		count += ft_hexa(va_arg(ap, unsigned int));
	else if (percent == 'X')
		count += ft_hexaup(va_arg(ap, unsigned int));
	else if (percent == 'p')
		count += ft_ptr(va_arg(ap, unsigned long));
	else
		count += write(1, &percent, 1);
	return (count);
}
