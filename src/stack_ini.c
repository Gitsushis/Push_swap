/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:05:40 by cbouyer           #+#    #+#             */
/*   Updated: 2025/06/01 20:07:42 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"
#include <stdio.h>

/*initialises the double linked list*/
void	ft_ini_list(t_doublelink *list)
{
	list -> head = NULL;
	list -> tails = NULL;
}

/*Checks for empty list, if empty returns 1, if not returns -1*/
int	ft_isempty(t_doublelink *list)
{
	if (list -> head == NULL)
		return (1);
	else
		return (-1);
}

/*node insertion from end*/
void	ft_insert_end(t_doublelink *list, int value)
{
	t_list_swap	*newnode;

	newnode = (t_list_swap *)malloc(sizeof(t_list_swap));
	if (!newnode)
		return ;
	newnode -> data = value;
	newnode -> next = NULL;
	newnode -> previous = list -> tails;
	if (!list -> head)
		list -> head = newnode;
	else
		list -> tails -> next = newnode;
	list -> tails = newnode;
}

static int	process_atoi(char **num, t_doublelink *list)
{
	int		j;
	long	n;

	j = 0;
	while (num[j])
	{
		n = ft_atoi(num[j]);
		if (n < INT_MIN || n > INT_MAX)
		{
			write (2, "Error\n", 6);
			ft_free_split(num);
			exit(EXIT_FAILURE);
		}
		ft_insert_end(list, n);
		free(num[j]);
		j++;
	}
	free(num);
	return (0);
}

void	ft_arg_to_list(int argc, char *argv[], t_doublelink *list)
{
	int		i;
	char	**num;

	i = 1;
	while (i < argc)
	{
		num = ft_split(argv[i], ' ');
		if (!num)
		{
			ft_freelist(list);
			return ;
		}
		process_atoi(num, list);
		i++;
	}
}
