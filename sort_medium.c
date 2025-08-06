/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:06:03 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/29 16:51:46 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	pushed_count;

	chunk_size = a->size / 5;
	chunk_min = 0;
	chunk_max = chunk_min + chunk_size;
	pushed_count = 0;
	while (a->size > 0)
	{
		if (a->top->index >= chunk_min && a->top->index < chunk_max)
		{
			pb(a, b);
			pushed_count++;
			if (b->top->index < (chunk_min + chunk_max) / 2)
				rb(b);
		}
		else
			ra(a);
		if (pushed_count >= chunk_size)
		{
			chunk_min = chunk_max;
			chunk_max += chunk_size;
			pushed_count = 0; 
		}
	}

	while (b->size > 0)
	{
		move_index_to_top(b, find_pos_max_index(b));
		pa(a, b);
	}
}

