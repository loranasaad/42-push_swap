/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:28:40 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/21 17:49:57 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pos_to_top(t_stack *stack, int pos, char stack_name)
{
	int	size;

	if (!stack || pos < 0 || pos >= stack->size)
		return;
	size = stack->size;
	if (size / 2 >= pos)
		while(pos)
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
			pos--;
		}
	else
		while(size - pos > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
			pos++;
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

int	absolute(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}