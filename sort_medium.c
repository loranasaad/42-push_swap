/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:06:03 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/15 07:54:16 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	position;

	chunk_size = a->size / 7;
	if (chunk_size < 1)
		chunk_size = 1;
	chunk_min = 0;
	chunk_max = chunk_min + chunk_size;
	while (a->size > 0)
	{
		position = find_pos_in_chunk(chunk_min, chunk_max, a);
		if (position == -1)
		{
			chunk_min = chunk_max;
			chunk_max += chunk_size;
			continue;
		}
		else
		{
			move_pos_to_top(a, position, 'a');
			pb(a, b);
			if (b->top->index < (chunk_min + chunk_max) / 2)
				rb(b);
		}
	}
	while (b->size > 0)
	{
		move_pos_to_top(b, find_pos_max_index(b), 'b');
		pa(a, b);
	}
}

