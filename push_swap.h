/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:10:06 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/28 23:47:52 by loasaad          ###   ########.fr       */
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
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;


void	sort_stack(t_stack *a, t_stack *b);

int		is_sorted(t_stack *a);
int		is_duplicate(t_stack *a, int n);
void	ps_free_stack(t_stack *a);
int		ps_atoi_safe(const char *str, int *result);
int		ps_lst_add_back(t_stack *a, int n);

void	free_input_list(char **input_list);
int		parse_input(int argc, char **argv, t_stack *a);

int		find_min_index(t_stack *stack);
void	move_index_to_top (t_stack *stack, int	index);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
int		reverse_rot_stack(t_stack *stack);
void 	rra(t_stack *a);
void 	rrb(t_stack *b);
void 	rrr(t_stack *a, t_stack *b);
int		rotate_stack(t_stack *stack);
void 	ra(t_stack *a);
void 	rb(t_stack *b);
void 	rr(t_stack *a, t_stack *b);
int		swap_stack(t_stack *stack);
void 	sa(t_stack *a);
void 	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

#endif