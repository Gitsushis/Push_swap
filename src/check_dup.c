/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:45:40 by candrabouye       #+#    #+#             */
/*   Updated: 2025/06/01 19:41:00 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static	int	count_total_numbers(int argc, char *argv[])
{
	char	**split;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (count);
}

static int	fill_num_array(int *num, int argc, char *argv[])
{
	char	**split;
	int		i;
	int		k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		if (handle_split(split, num, &k) == -1)
		{
			ft_free_split(split);
			return (-1);
		}
		ft_free_split(split);
		i++;
	}
	return (0);
}

static int	has_dup(int *num, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (num[i] == num[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dup_arg(int argc, char *argv[])
{
	int	*num;
	int	count;
	int	result;

	count = count_total_numbers(argc, argv);
	if (count < 0)
		return (-1);
	num = malloc(sizeof(int) * count);
	if (!num)
		return (-1);
	if (fill_num_array(num, argc, argv) == -1)
		return (free(num), -1);
	result = has_dup(num, count);
	free(num);
	return (result);
}
