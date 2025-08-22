/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:56:37 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/21 18:22:32 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_at_pos(t_stack *stack, int pos)
{
	t_node	*current;
	int		i;
	
	if (!stack || pos < 0 || pos >= stack->size)
		return (-1);
	current = stack->top;
	i = 0;
	while (current && i < pos)
	{
		current = current->next;
		i++;
	}
	if (!current)
		return (-1);
	return (current->index);
}

int	find_pos_min_index(t_stack *stack)
{
	int		min_index;
	int		min_position;
	t_node	*current;
	int		i;
	
	if (!stack || stack->size <= 0)
		return (-1);
	current = stack->top;
	min_index = current->index;
	min_position = 0;
	i = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_position = i;
		}
		current = current->next;
		i++;
	}
	return (min_position);
}

int	find_pos_max_index(t_stack *stack)
{
	int		max_index;
	int		max_position;
	t_node	*current;
	int		i;
	
	max_index = -1;
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
int	find_pos_in_chunk(int chunk_min, int chunk_max, t_stack *stack)
{
	t_node	*current;
	int		i;
	
	if (!stack || stack->size <= 0)
		return (-1);
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