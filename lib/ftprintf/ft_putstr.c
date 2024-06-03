/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:33:49 by drenquin          #+#    #+#             */
/*   Updated: 2024/03/27 21:30:57 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = -1;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		ft_putchar((int)*str);
		count++;
		str++;
	}
	return (count);
}
