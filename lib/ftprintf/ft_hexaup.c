/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:20:37 by drenquin          #+#    #+#             */
/*   Updated: 2024/03/27 23:39:18 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexaup(unsigned int nb)
{
	int		i;
	int		count;
	char	buffer[15];
	char	*base;

	base = "0123456789ABCDEF";
	if (nb == 0)
	{
		ft_putchar(base[0]);
		return (0);
	}
	count = 0;
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
