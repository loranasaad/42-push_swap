/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:28:40 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/12 12:52:09 by loasaad          ###   ########.fr       */
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

void	move_pos_to_top(t_stack *stack, int index)
{
	
	if ((stack->size) / 2 > index)
		while(index)
		{
			ra(stack);
			index--;
		}
	else
		while(stack->size - index > 0)
		{
			rra(stack);
			index++;
		}
}

void	assign_indexes(t_stack *a)
{
	int		*arr;
	t_node	*current;
	int		i;
	
	arr = fill_array(a);
	if (!arr)
		return;
	bubble_sort(arr, a->size);
	current = a->top;
	while (current)
	{
		i = 0;
		while (i < a->size)
		{
			if (arr[i] == current->number)
			{
				current->index = i;
				break;
			}
			i++;
		}
		current = current->next;
	}
	free(arr);
}
int	*fill_array(t_stack *a)
{
	int		*arr;
	t_node	*current;
	int		i;
	
	arr = malloc(sizeof(int)*a->size);
	if(!arr)
		return (NULL);
	current = a->top;
	i = 0;
	while(current)
	{
		arr[i] = current->number;
		i++;
		current = current->next;
	}
	return (arr);
}

void bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	
	i = 0;
	while (i < size -1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}