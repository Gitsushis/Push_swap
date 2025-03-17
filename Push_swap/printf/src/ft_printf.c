/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:19:10 by cbouyer           #+#    #+#             */
/*   Updated: 2025/01/16 17:28:22 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int n)
{
	write(1, &n, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	lengths;

	lengths = 0;
	if (format == 'c')
		lengths += ft_putchar(va_arg(args, int));
	else if (format == 's')
		lengths += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		lengths += ft_print_ptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		lengths += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		lengths += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		lengths += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		lengths += ft_printpercent();
	return (lengths);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
