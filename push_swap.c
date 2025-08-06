/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:10:26 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/29 15:37:11 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else if (a->size <= 100)
	{
		assign_indexes(a);
		sort_chunks(a, b);
	}
	else if (a->size > 100)
	{
		assign_indexes(a);
		sort_chunks_l(a, b);
	}
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (!parse_input(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		ps_free_stack(&a);
		return (1);
	}
	if (a.size == 0 || is_sorted(&a))
	{
		ps_free_stack(&a);
		return (0);
	}
	sort_stack(&a, &b);
	
	// t_node	*current = a.top;
	// while (current)
	// {
	// 	printf("%d\n", current->number);
	// 	current = current->next;
	// }
	
	// ps_free_stack(&a);
	return (0);	
}