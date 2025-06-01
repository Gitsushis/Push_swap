/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:07:08 by candrabouye       #+#    #+#             */
/*   Updated: 2025/06/01 19:53:54 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

//allows the sorting of 3 elements
void	tiny_sort_3(t_doublelink *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !a->head || !a->head->next || !a->head->next->next)
		return ;
	first = a->head->data;
	second = a->head->next->data;
	third = a->head->next->next->data;
	if (first < second && second < third)
	{
		sa(a);
		rra(a);
	}
	else if (first < third && third < second)
		rra(a);
	else if (second < first && first < third)
	{
		sa(a);
		rra(a);
	}
	else if (second < third && third < first)
		sa(a);
	else if (third < first && first < second)
		rra(a);
}

void	tiny_sort_2(t_doublelink *a)
{
	int	first;
	int	second;

	first = a -> head -> data;
	second = a -> head -> next -> data;
	if (first < second)
		sa(a);
}

void	tiny_sort_4(t_doublelink *a, t_doublelink *b)
{
	push_max_b(a, b);
	tiny_sort_3(a);
	pa(a, b);
}

void	tiny_sort_5(t_doublelink *a, t_doublelink *b)
{
	push_max_b(a, b);
	push_max_b(a, b);
	tiny_sort_3(a);
	pa(a, b);
	pa(a, b);
}
