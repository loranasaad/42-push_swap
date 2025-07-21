/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:39:14 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/21 17:05:39 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	ps_atoi_safe(const char *str, int *result)
{
	int		i;
	int		sign;
	long	numb;

	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	numb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (str[i] - '0') + (10 * numb);
		if ((sign == 1 && numb > INT_MAX) || (sign == -1 && -numb < INT_MIN))
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	*result = (int)(sign * numb);
	return (1);
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
