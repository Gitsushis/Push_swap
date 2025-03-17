/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:49:51 by cbouyer           #+#    #+#             */
/*   Updated: 2025/03/03 14:49:53 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

/*function checks for errors (int only, negs...)*/
int	error_handling(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i <= argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				j++;
			if (argv[i][j] == ' ' || argv[i][j] == '\t')
			{
				j++;
				continue ;
			}
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

/*function finding the size of the arguments for malloc*/
int	list_size(int *argc, char *argv[])
{
	int	i;
	int y;
	int	size;

	i = 1;
	while (argc < i)
	{
		size = ft_split(argv[i], " ");
		i++;
	}
}


/*Function checking for duplicates*/

int	check_dupes()
{}