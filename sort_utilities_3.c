/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:44:47 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/21 14:27:39 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	calculate_dist(int pos, int size)
{
	if (pos <= 0 || size <= 0 || pos >= size)
		return (0);
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

int	pos_insert_a(t_stack *a, int index_b)
{
	t_node	*current;
	int		index_min;
	int		pos_min;
	int		index_prev;
	int		i;
	
	if (!a || a->size == 0)
		return (0);
	pos_min = find_pos_min_index(a);
	index_min = get_index_at_pos(a, pos_min);
	if (index_b < index_min || index_b > get_index_at_pos(a, find_pos_max_index(a)))
		return (pos_min);
	index_prev = get_index_at_pos(a, a->size - 1);
	current = a->top;
	i = 0;
	while (current)
	{
		if (index_prev < index_b && index_b < current->index)
			return (i);
		index_prev = current->index;
		current = current->next;
		i++;
	}
	return (pos_min);
}

void	overlap_rotate(int *rot_a, int *rot_b, t_stack *a, t_stack *b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		rr(a, b);
		(*rot_a)--;
		(*rot_b)--;
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		rrr(a, b);
		(*rot_a)++;
		(*rot_b)++;
	}
}




