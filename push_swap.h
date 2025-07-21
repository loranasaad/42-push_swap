/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:10:06 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/21 17:14:54 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX	2147483647
# define INT_MIN	(-2147483648)

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				number;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

int		push_swap(int argc, char **argv);
int		ps_atoi_safe(const char *str, int *result);
int		ps_lst_add_back(t_stack *a, int n);
int		is_duplicate(t_stack *a, int n);

#endif