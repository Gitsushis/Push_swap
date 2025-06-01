/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrabouyer <candrabouyer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:13:51 by cbouyer           #+#    #+#             */
/*   Updated: 2025/06/01 19:59:32 by candrabouye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Push_swap.h"

static void	swap(t_list_swap **head)
{
	t_list_swap	*first;
	t_list_swap	*second;

	if (!head || !*head || !(*head)-> next)
		return ;
	first = *head;
	second = first -> next;
	*head = second;
	first -> next = second -> next;
	first -> previous = second;
	if (second -> next)
		second -> next -> previous = first;
	second -> next = first;
	second -> previous = NULL;
}

void	sa(t_doublelink *a)
{
	swap(&a -> head);
	write (1, "sa\n", 3);
}

void	sb(t_doublelink *b)
{
	swap(&b -> head);
	write (1, "sb\n", 3);
}

void	ss(t_doublelink *a, t_doublelink *b)
{
	swap(&a -> head);
	swap(&b -> head);
	write (1, "ss\n", 3);
}
