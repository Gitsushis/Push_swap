/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <cbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:17:04 by cbouyer           #+#    #+#             */
/*   Updated: 2024/11/24 13:45:10 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
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
