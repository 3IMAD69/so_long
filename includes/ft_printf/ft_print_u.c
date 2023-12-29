/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:02:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/20 09:32:38 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_print_u(unsigned int nb)
{
	char	*dec_base;
	char	*final_number;
	int		size;
	int		result;

	dec_base = "0123456789";
	if (nb == 0)
		return (ft_putchar_fd('0', 1));
	size = get_size(nb);
	final_number = (char *)malloc(sizeof(char) * size + 1);
	if (!final_number)
		return (-1);
	final_number[size] = '\0';
	while (nb)
	{
		size--;
		final_number[size] = dec_base[(nb % 10)];
		nb /= 10;
	}
	result = ft_putstr_fd(final_number, 1);
	free(final_number);
	return (result);
}
