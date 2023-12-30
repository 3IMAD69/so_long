/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:02:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/20 09:32:50 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

static void	write_to_result(char *final_number, unsigned int nb, size_t size,
		char maj)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	final_number[size] = '\0';
	while (nb)
	{
		size--;
		if (maj == 'X' && (nb % 16) > 9)
			final_number[size] = hex_base[(nb % 16)] - 32;
		else
			final_number[size] = hex_base[(nb % 16)];
		nb /= 16;
	}
}

int	ft_print_x(unsigned int nb, char maj)
{
	char	*final_number;
	size_t	size;
	int		result;

	if (nb == 0)
		return (ft_putchar_fd('0', 1));
	size = get_size(nb);
	final_number = (char *)malloc(sizeof(char) * size + 1);
	if (!final_number)
		return (-1);
	write_to_result(final_number, nb, size, maj);
	result = ft_putstr_fd(final_number, 1);
	free(final_number);
	return (result);
}
