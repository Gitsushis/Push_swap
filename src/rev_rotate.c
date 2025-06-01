/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:06:43 by candrabouye       #+#    #+#             */
/*   Updated: 2025/06/01 19:59:32 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

static void	rev_rotate(t_list_swap **head, t_list_swap **tail)
{
	t_list_swap	*last;
	t_list_swap	*second_last;

	if (!tail || !*tail || !(*tail)-> previous)
		return ;
	last = *tail;
	second_last = last -> previous;
	second_last -> next = NULL;
	last -> previous = NULL;
	last -> next = *head;
	(*head)-> previous = last;
	*head = last;
	*tail = second_last;
}

void	rra(t_doublelink *a)
{
	rev_rotate(&a -> head, &a -> tails);
	write (1, "rra\n", 4);
}

void	rrb(t_doublelink *b)
{
	rev_rotate(&b -> head, &b -> tails);
	write (1, "rrb\n", 4);
}

void	rrr(t_doublelink *a, t_doublelink *b)
{
	rev_rotate(&a -> head, &a -> tails);
	rev_rotate(&b -> head, &b -> tails);
	write (1, "rrr\n", 4);
}
