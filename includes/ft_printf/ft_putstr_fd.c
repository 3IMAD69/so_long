/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:07:19 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/19 13:27:38 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	printed;

	printed = 0;
	if (fd < 0 || !s)
		return (0);
	while (*s)
	{
		if (ft_putchar_fd(*s++, fd) == -1)
			return (-1);
		else
			printed++;
	}
	return (printed++);
}
