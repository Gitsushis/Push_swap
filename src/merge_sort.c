/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:29:29 by candrabouye       #+#    #+#             */
/*   Updated: 2025/06/01 19:53:54 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

void	push_back_to_a(t_doublelink *a, t_doublelink *b)
{
	int	max;
	int	pos;
	int	size;

	while (b -> head)
	{
		max = find_max_index(b);
		pos = get_position(b, max);
		size = count_stack(b);
		if (pos <= size / 2)
			while (pos--)
				rb(b);
		else
			while (++pos <= size)
				rrb(b);
		pa(a, b);
	}
}

void	push_chunks_to_b(t_doublelink *a, t_doublelink *b, int chunk, int total)
{
	int	limit;
	int	pushed;
	int	pos;

	limit = chunk;
	pushed = 0;
	while (pushed < total)
	{
		pos = find_next_index_pos(a, limit);
		if (pos == -1)
			limit += chunk;
		if (pos == 0)
		{
			pb(a, b);
			if (b->head->index < limit - (chunk / 2))
				rb(b);
			pushed++;
			if (pushed % chunk == 0)
				limit += chunk;
		}
		else
			rotate_to_top(a, pos);
	}
}

void	merge_sort(t_doublelink *a, t_doublelink *b)
{
	int	chunk;
	int	size;

	size = count_stack(a);
	if (size <= 25)
		chunk = 1;
	else if (size <= 50)
		chunk = 5;
	else if (size <= 100)
		chunk = 20;
	else if (size <= 300)
		chunk = 30;
	else
		chunk = 65;
	if (!a || !a -> head)
		return ;
	assign_index(a);
	push_chunks_to_b(a, b, chunk, size);
	push_back_to_a(a, b);
}
