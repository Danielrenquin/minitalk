/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:52:23 by drenquin          #+#    #+#             */
/*   Updated: 2024/06/03 18:54:41 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include "lib/ftprintf/ft_printf.h"
#include "lib/libft/libft.h"

void	char_to_bit(char c, __pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c &(0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			char_to_bit(argv[2][i], pid);
			i++;
		}
		char_to_bit('\n', pid);
		return (0);
	}
	else
	{
		ft_printf("usage: %s <pid> <string>\n", argv[0]);
		return (1);
	}
}
