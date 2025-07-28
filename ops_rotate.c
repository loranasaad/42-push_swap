/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:02:05 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/28 15:36:09 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*first;
	
	if (stack->size < 2)
		return (0);
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = stack->top->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate_stack(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (rotate_stack(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	is_rotated;
	
	is_rotated = 0;
	is_rotated += rotate_stack(a);
	is_rotated += rotate_stack(b);
	if (is_rotated)
		write(1, "rr\n", 3);
}