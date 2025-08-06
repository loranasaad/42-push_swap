/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:56:37 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/06 19:37:37 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_max_index(t_stack *stack)
{
	int		max_index;
	int		max_position;
	t_node	*current;
	int		i;
	
	max_index = 0;
	max_position = 0;
	current = stack->top;
	i = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_position = i;
		}
		current = current->next;
		i++;
	}
	return (max_position);
}

int	find_in_chunk (int	chunk_min, int chunk_max, t_stack *stack)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		if (current->index < chunk_max && current->index >= chunk_min)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}