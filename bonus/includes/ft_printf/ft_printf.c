/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:26:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/20 12:04:38 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_print_error(int result, va_list args, int *printed_chars)
{
	if (result == -1)
	{
		va_end(args);
		return (-1);
	}
	*printed_chars += result;
	return (0);
}

static void	input_checker(const char *str, va_list args, int *result)
{
	if (*str == 'd' || *str == 'i')
		*result = ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str == 'c')
		*result = ft_putchar_fd((char)va_arg(args, int), 1);
	else if (*str == 's')
		*result = ft_print_str(va_arg(args, char *));
	else if (*str == 'p')
		*result = ft_print_p(va_arg(args, void *));
	else if (*str == 'x' || *str == 'X')
		*result = ft_print_x(va_arg(args, unsigned int), *str);
	else if (*str == 'u')
		*result = ft_print_u(va_arg(args, unsigned int));
	else if (*str == '%')
		*result = ft_putchar_fd('%', 1);
	else if (*str != '\0')
		*result = ft_putchar_fd(*str, 1);
	else if (*str == '\0')
		*result = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;
	int		result;

	result = 0;
	printed_chars = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0' && (str++))
		{
			input_checker(str, args, &result);
			if (handle_print_error(result, args, &printed_chars) == -1)
				return (-1);
		}
		else
		{
			if (*str != '%' && handle_print_error(ft_putchar_fd(*str, 1), args,
					&printed_chars) == -1)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (printed_chars);
}
