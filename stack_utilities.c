/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:39:14 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/05 18:09:23 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;
	
	current = a->top;
	if (a->size < 2)
		return (1);
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_duplicate(t_stack *a, int n)
{
	t_node	*current;
	
	current = a->top;
	while (current)
	{
		if (n == current->number)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ps_free_stack(t_stack *a)
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

int	ps_lst_add_back(t_stack *a, int n)
{
	t_node	*new;
	t_node	*current;
	
	if (is_duplicate(a, n))
		return (0);
	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->number = n;
	new->next = NULL;
	if (a->top == NULL)
		a->top = new;
	else
	{
		current = a->top;
		while (current-> next)
			current = current->next;
		current->next = new;
	}
	a->size++;
	return (1);
}