/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:49:51 by cbouyer           #+#    #+#             */
/*   Updated: 2025/06/01 20:00:15 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[1] == '\0')
			return (0);
		i = 1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int argc, char *argv[])
{
	int			i;
	int			j;
	char		**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			if (!is_valid_num(split[j]))
			{
				ft_free_split(split);
				return (-1);
			}
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (0);
}

//frees all memory from doublelink after usage
void	ft_freelist(t_doublelink *list)
{
	t_list_swap	*current;
	t_list_swap	*temp;

	current = list -> head;
	while (current)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}
	list -> head = NULL;
	list -> tails = NULL;
}

int	count_stack(t_doublelink *a)
{
	int			count;
	t_list_swap	*current;

	count = 0;
	current = a -> head;
	while (current)
	{
		count++;
		current = current -> next;
	}
	return (count);
}
