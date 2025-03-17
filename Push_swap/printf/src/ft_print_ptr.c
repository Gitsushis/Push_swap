/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:19:58 by cbouyer           #+#    #+#             */
/*   Updated: 2025/01/16 17:38:28 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//gives lengths and formats base 10 int into hexadecimal
int	ft_print_len(uintptr_t num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

//converts the number given into hexadecimal
void	ft_put_ptr(uintptr_t num)
{
	char	c;

	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num < 10)
			c = num + '0';
		else
			c = num - 10 + 'a';
		write (1, &c, 1);
	}
}

//prints the pointer
int	ft_print_ptr(uintptr_t ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
	{
		print_length += write(1, "(nil)", 5);
	}
	else
	{
		print_length += write(1, "0x", 2);
		ft_put_ptr(ptr);
		print_length += ft_print_len(ptr);
	}
	return (print_length);
}
