/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:27:30 by drenquin          #+#    #+#             */
/*   Updated: 2024/03/27 23:45:20 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexa(unsigned int nb)
{
	char	*base;
	char	buffer[15];
	int		count;
	int		i;

	base = "0123456789abcdef";
	count = 0;
	if (nb == 0)
	{
		ft_putchar(base[0]);
		return (0);
	}
	while (nb)
	{
		buffer[count++] = base[nb % 16];
		nb /= 16;
	}
	i = count;
	while (--count >= 0)
		ft_putchar(buffer[count]);
	return (i - 1);
}
