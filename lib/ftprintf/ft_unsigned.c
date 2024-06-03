/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:50:08 by drenquin          #+#    #+#             */
/*   Updated: 2024/03/27 21:28:49 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_unsigned(unsigned int nb)
{
	short		i;
	char		buffer[10];
	int			count;

	i = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (0);
	}
	while (nb)
	{
		buffer[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	count = i;
	while (i > 0)
		ft_putchar(buffer[--i]);
	return (count - 1);
}
