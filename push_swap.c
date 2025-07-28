/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:10:26 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/24 16:01:31 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack *a)
{
	t_node	*current;
	t_node	*next;

	current = a->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int push_swap(int argc, char **argv)
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
		free_stack(&a);
		return (1);
	}
	if (a.size == 0 || is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	// ps_sorting;
	free_stack(&a);
	return (0);	
}