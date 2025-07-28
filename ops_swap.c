/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:00:34 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/28 15:41:00 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return (0);
	temp = stack->top->number;
	stack->top->number = stack->top->next->number;
	stack->top->next->number = temp;
	return (1);
}

void	sa(t_stack *a)
{
	if (swap_stack(a))
		write (1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (swap_stack(b))
		write (1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	swapped;

	swapped = 0;
	swapped += swap_stack(a);
	swapped += swap_stack(b);
	if (swapped)
		write (1, "ss\n", 3);
}
