/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:15:12 by candrabouye       #+#    #+#             */
/*   Updated: 2025/06/01 20:26:08 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

int	find_max_index(t_doublelink *b)
{
	t_list_swap	*node;
	int			max;

	if (!b || !b -> head)
		return (-1);
	node = b -> head;
	max = node -> index;
	while (node)
	{
		if (node -> index > max)
			max = node -> index;
		node = node -> next;
	}
	return (max);
}

int	get_position(t_doublelink *list, int index)
{
	t_list_swap	*node;
	int			i;

	node = list ->head;
	i = 0;
	while (node)
	{
		if (node -> index == index)
			return (i);
		node = node -> next;
		i++;
	}
	return (-1);
}

void	assign_index(t_doublelink *list)
{
	t_list_swap	*ptr1;
	t_list_swap	*ptr2;
	int			index;

	ptr1 = list -> head;
	while (ptr1)
	{
		index = 0;
		ptr2 = list -> head;
		while (ptr2)
		{
			if (ptr2 -> data < ptr1 -> data)
				index++;
			ptr2 = ptr2 -> next;
		}
		ptr1 -> index = index;
		ptr1 = ptr1 -> next;
	}
}

int	find_next_index_pos(t_doublelink *stack, int limit)
{
	t_list_swap	*node;
	int			pos;

	node = stack->head;
	pos = 0;
	while (node)
	{
		if (node->index < limit)
			return (pos);
		node = node->next;
		pos++;
	}
	return (-1);
}

void	rotate_to_top(t_doublelink *stack, int pos)
{
	int	size;

	size = count_stack(stack);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack);
	else
	{
		while (pos++ < size)
			rra(stack);
	}
}
