/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:04:14 by cbouyer           #+#    #+#             */
/*   Updated: 2025/06/01 19:59:32 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

static void	rotate(t_list_swap **head, t_list_swap **tail)
{
	t_list_swap	*first;

	if (!head || !*head || !(*head)-> next || !tail || !*tail)
		return ;
	first = *head;
	*head = first -> next;
	(*head)-> previous = NULL;
	(*tail)-> next = first;
	first -> previous = *tail;
	first -> next = NULL;
	*tail = first;
}

void	ra(t_doublelink *a)
{
	rotate(&a -> head, &a -> tails);
	write (1, "ra\n", 3);
}

void	rb(t_doublelink *b)
{
	rotate(&b -> head, &b -> tails);
	write (1, "rb\n", 3);
}

void	rr(t_doublelink *a, t_doublelink *b)
{
	rotate(&a -> head, &a -> tails);
	rotate(&b -> head, &b -> tails);
	write (1, "rr\n", 3);
}
