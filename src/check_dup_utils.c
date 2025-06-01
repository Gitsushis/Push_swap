/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:37:56 by candrabouye       #+#    #+#             */
/*   Updated: 2025/06/01 19:40:49 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

int	handle_split(char **split, int *num, int *k)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (!is_valid_num(split[j]))
			return (-1);
		num[(*k)++] = ft_atoi(split[j]);
		j++;
	}
	return (0);
}
