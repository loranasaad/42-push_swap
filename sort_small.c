/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:43:50 by loasaad           #+#    #+#             */
/*   Updated: 2025/08/12 12:52:46 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (!is_sorted(a))
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a->top->number;
	num2 = a->top->next->number;
	num3 = a->top->next->next->number;

	if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(a);
	else if (num1 > num2 && num2 > num3)
	{	
		sa(a);
		rra(a);
	}
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(a);
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{	
		rra(a);
		sa(a);
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	move_pos_to_top(a, find_min_index(a));
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	move_pos_to_top(a, find_min_index(a));
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}