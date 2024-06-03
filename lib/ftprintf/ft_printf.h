/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:26:39 by drenquin          #+#    #+#             */
/*   Updated: 2024/03/28 00:13:44 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_cspdiux(char percent, va_list ap);
int				ft_putnbr(int nb);
unsigned int	ft_unsigned(unsigned int nb);
int				ft_hexa(unsigned int nb);
int				ft_hexaup(unsigned int nb);
int				ft_ptr(unsigned long nb);

#endif
