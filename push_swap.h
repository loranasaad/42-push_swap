/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:10:06 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/05 18:25:29 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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
int		atoi_safe(const char *str, int *result);
int		ps_lst_add_back(t_stack *a, int n);
void	free_input_list(char **input_list);
int		parse_input(int argc, char **argv, t_stack *a);
void	move_pos_to_top(t_stack *stack, int pos, char stack_name);
void	assign_indexes(t_stack *a);
int		*fill_array(t_stack *a);
void 	bubble_sort(int *arr, int size);
int		absolute(int x);
int		get_index_at_pos(t_stack *stack, int pos);
int		find_pos_max_index(t_stack *stack);
int		find_pos_in_chunk (int	chunk_min, int chunk_max, t_stack *stack);
int		find_pos_min_index(t_stack *stack);
int		calculate_dist(int pos, int size);
int		pos_insert_a(t_stack *a, int index_b);
void	overlap_rotate(t_stack *a, t_stack *b, int *rot_a, int *rot_b);
int		candidate_cost(t_stack *a, t_stack *b, int pos_b);
int		best_candidate(t_stack *a, t_stack *b);
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
void	push_to_b(t_stack *a, t_stack *b, int chunks);
void	finish_rotate(t_stack *a, t_stack *b, int rot_a, int rot_b);
void	return_to_a(t_stack *a, t_stack *b);
void	normalize_a(t_stack *a);
void	sort_big(t_stack *a, t_stack *b);
char	**ft_split(char const *s, char c);

#endif