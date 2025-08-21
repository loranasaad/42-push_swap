/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:06:03 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/21 17:56:04 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int chunks)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	pos;
	
	chunk_size = a->size / chunks;
	if (chunk_size < 1)
		chunk_size = 1;
	chunk_min = 0;
	chunk_max = chunk_min + chunk_size;
	while (a->size > 0)
	{
		pos = find_pos_in_chunk(chunk_min, chunk_max, a);
		if (pos == -1)
		{
			chunk_min = chunk_max;
			chunk_max += chunk_size;
			continue;
		}
		move_pos_to_top(a, pos, 'a');
		pb(a, b);
	}
}

void	finish_rotate(t_stack *a, t_stack *b, int rot_a, int rot_b)
{
	while (rot_b > 0)
	{
		rb(b);
		rot_b--;
	}
	while (rot_b < 0)
	{
		rrb(b);
		rot_b++;
	}
	while (rot_a > 0)
	{
		ra(a);
		rot_a--;
	}
	while (rot_a < 0)
	{
		rra(a);
		rot_a++;
	}
}

void	return_to_a(t_stack *a, t_stack *b)
{
	int	pos_a;
	int	pos_b;
	int	rot_a;
	int	rot_b;
	int	index_b;

	while (b->size > 0)
	{
		pos_b = best_candidate(a, b);
		index_b = get_index_at_pos(b, pos_b);
		pos_a = pos_insert_a(a, index_b);
		rot_a = calculate_dist(pos_a, a->size);
		rot_b = calculate_dist(pos_b, b->size);
		overlap_rotate(a, b, &rot_a, &rot_b);
		finish_rotate(a, b, rot_a, rot_b);
		pa(a, b);
	}
}

void	normalize_a(t_stack *a)
{
	int pos_min_a;
	
	pos_min_a = find_pos_min_index(a);
	if (pos_min_a >= 0)
		move_pos_to_top(a, pos_min_a, 'a');
}
void	sort_big(t_stack *a, t_stack *b)
{
	int	chunks;
	
	chunks = a->size / 200;
	if (chunks < 1)
		chunks = 1; 
	push_to_b(a, b, chunks);
	return_to_a(a, b);
	normalize_a(a);
}