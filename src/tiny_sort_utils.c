/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:33:48 by candrabouye       #+#    #+#             */
/*   Updated: 2025/06/01 20:00:07 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

int	find_min_index(t_doublelink *stack)
{
	t_list_swap	*node;
	int			index;
	int			i;
	int			min;

	node = stack -> head;
	index = 0;
	i = 0;
	min = node -> data;
	while (node)
	{
		if (node -> data < min)
		{
			min = node -> data;
			index = i;
		}
		node = node -> next;
		i++;
	}
	return (index);
}

void	push_min_b(t_doublelink *a, t_doublelink *b)
{
	int	index;
	int	size;
	int	rot;

	index = find_min_index(a);
	size = count_stack(a);
	if (index <= size / 2)
		while (index-- > 0)
			ra(a);
	else
	{
		rot = size - index;
		while (rot-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	push_max_b(t_doublelink *a, t_doublelink *b)
{
	int	max_index;
	int	pos;
	int	size;

	if (!a || !a->head)
		return ;
	max_index = find_max_index(a);
	pos = get_position(a, max_index);
	size = count_stack(a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
	pb(a, b);
}
