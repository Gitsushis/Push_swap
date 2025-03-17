/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:05:40 by cbouyer           #+#    #+#             */
/*   Updated: 2025/03/13 15:05:41 by cbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

/*initialises the double linked list
new_node stores value as data
next points to the node afterwards
previous points to the previous node*/
s_list	*ini_node(int value)
{
	s_list	*new_node;

	new_node = (s_list *)malloc(sizeof(s_list));
	if (!new_node)
		return (NULL);
	new_node -> data = value;
	new_node -> next = NULL;
	new_node -> previous = NULL;
	return (new_node);
}

/*void	arg_to_list(int argc, char *argv[], void *content)
{
	int	i;
	int	count;
	char	**content;

	i = 1;
	count = 0;
	*a = malloc(argc[MAX_SIZE] * sizeof(int));
	if (!*a)
		return (NULL);
	while (argc > i)
	{
		content = ft_split(argv[i], " ");
		i++;
	}
	i = 0;
	while (content[i])
	{
		(*a)[count] = ft_atoi(content[i]);
		i++;
		count++;
	}
	free(content);
}
*/