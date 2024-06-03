/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:46:07 by drenquin          #+#    #+#             */
/*   Updated: 2024/03/27 21:45:47 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ptr(unsigned long ptr)
{
	char	*base;
	char	buffer[20];
	int		count;
	int		i;

	count = 0;
	base = "0123456789abcdef";
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (4);
	}
	write(1, "0x", 2);
	while (ptr)
	{
		buffer[count++] = base[ptr % 16];
		ptr /= 16;
	}
	i = count;
	while (--count >= 0)
		ft_putchar(buffer[count]);
	return (i + 1);
}
