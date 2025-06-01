/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:19:43 by cbouyer           #+#    #+#             */
/*   Updated: 2025/01/16 17:35:56 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	number_size(int nb)
{
	unsigned int	length;

	length = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		length++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

static char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	nb;
	unsigned int	len;

	len = number_size(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	if (n < 0)
	{
		nb = -n;
		string[0] = '-';
	}
	else
		nb = n;
	string[len] = '\0';
	if (nb == 0)
		string[0] = '0';
	while (nb != 0)
	{
		string[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (string);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
