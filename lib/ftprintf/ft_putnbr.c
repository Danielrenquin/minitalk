/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:17:01 by drenquin          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:51 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_countnb(int nb)
{
	int	count;

	count = -1;
	if (nb == 0)
		return (0);
	if (nb == -2147483648)
		return (10);
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	long	nbl;
	short	i;
	char	buffer[10];

	i = 0;
	nbl = nb;
	if (nb == 0)
		ft_putchar('0');
	if (nbl < 0)
	{
		nbl *= -1;
		ft_putchar('-');
	}
	while (nbl)
	{
		buffer[i++] = (nbl % 10) + 48;
		nbl = nbl / 10;
	}
	while (i > 0)
		ft_putchar(buffer[--i]);
	return (ft_countnb(nb));
}
