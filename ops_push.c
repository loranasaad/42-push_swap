/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:02:04 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/24 16:02:37 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;
	
	if (b->top == NULL)
		return;
	temp = b->top;
	b->top = b->top->next;
	temp->next = a->top;
	a->top = temp;
	b->size--;
	a->size++;
	write (1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;
	
	if (a->top == NULL)
		return;
	temp = a->top;
	a->top = a->top->next;
	temp->next = b->top;
	b->top = temp;
	a->size--;
	b->size++;
	write (1, "pb\n", 3);
}