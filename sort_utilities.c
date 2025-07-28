/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:28:40 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/28 22:20:10 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	int		min_index;
	int		min_number;
	t_node	*current;
	int		i;
	
	min_index = 0;
	min_number = stack->top->number;
	current = stack->top;
	i = 0;
	while (current)
	{
		if (current->number < min_number)
		{
			min_number = current->number;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void	move_index_to_top (t_stack *stack, int	index)
{
	
	if ((stack->size)/2 > index)
		while(index)
		{
			ra(stack);
			index--;
		}
	else
		while(stack->size - index)
		{
			rra(stack);
			index++;
		}
}