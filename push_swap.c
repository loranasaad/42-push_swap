/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:10:26 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/21 18:04:56 by loasaad          ###   ########.fr       */
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
	t_stack	*a;

	a = NULL;
	if (!parse_input(argc, argv, a))
	{
		write(1, "Error\n", 6);
		free_stack(a);
		return (1);
	}
	if (!a || is_sorted(a))
		return (0);
	// ps_sorting;
	// free memory
	return (0);	
}