/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:37:23 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/19 13:27:35 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(long nb, int fd)
{
	int		printed_chars;
	long	divisor;

	divisor = 1;
	printed_chars = 0;
	if (nb < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		printed_chars++;
		nb = -nb;
	}
	while (nb / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		if (ft_putchar_fd((nb / divisor) + '0', 1) == -1)
			return (-1);
		printed_chars++;
		nb %= divisor;
		divisor /= 10;
	}
	return (printed_chars);
}
