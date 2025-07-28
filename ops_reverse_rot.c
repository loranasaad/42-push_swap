/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:02:01 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/28 16:01:33 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rot_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;
	
	if (stack->size < 2)
		return (0);
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}	
	if (second_last)
		second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	return (1);
}

void rra(t_stack *a)
{
	if (reverse_rot_stack(a))
		write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
	if (reverse_rot_stack(b))
		write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
	int	rotated;

	rotated = 0;
	rotated += reverse_rot_stack(a);
	rotated += reverse_rot_stack(b);
	if (rotated)
		write(1, "rrr\n", 4);
}