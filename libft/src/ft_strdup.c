/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <cbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:23:10 by cbouyer           #+#    #+#             */
/*   Updated: 2024/11/24 14:24:30 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*str2;

	i = 0;
	len = ft_strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
		return (NULL);
	while (i < len)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

/*Strdup creates a new string copy of the original source and creates
the necessary memory for the newly created sring*/