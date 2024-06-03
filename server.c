/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:52:39 by drenquin          #+#    #+#             */
/*   Updated: 2024/06/03 18:44:56 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include "lib/ftprintf/ft_printf.h"
#include "lib/libft/libft.h"

void	signal_handler(int signum)
{
	static char	received_bits[8];
	static int	bit_index = 0;
	int			i;
	char		c;

	if (bit_index < 8)
	{
		if (signum == SIGUSR1)
			received_bits[bit_index] = 1;
		else if (signum == SIGUSR2)
			received_bits[bit_index] = 0;
		bit_index++;
	}
	if (bit_index == 8)
	{
		c = 0;
		i = 0;
		while (i < 8)
		{
			c |= (received_bits[i] << i);
			i++;
		}
		write(1, &c, 1);
		bit_index = 0;
	}
}

int	main(void)
{
	int	i;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("PID: %d\n", getpid());
	i = 0;
	while (1)
	{
		pause();
	}
	return (0);
}
