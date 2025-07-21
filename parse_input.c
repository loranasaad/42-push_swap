/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:34:18 by loasaad           #+#    #+#             */
/*   Updated: 2025/07/21 17:12:06 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_input_list(char **input_list)
{
	int	i;

	i = 0;
	while (input_list[i])
	{
		free (input_list[i]);
		i++;
	}
	free (input_list);
}
int parse_input(int argc, char **argv, t_stack *a)
{
	char	**input_list;
	int		i;
	int		n;
	
	i = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		input_list = ft_split(argv[1], ' ');
	else if(argc > 2)
		input_list = &argv[1];
	while (input_list[i])
	{
		if (!ps_atoi_safe(input_list[i], &n) || !ps_lst_add_back(a, n))
		{
			if (argc == 2)
				free_input_list(input_list);
			return (0);
		}
		i++;
	}
	if (argc == 2)
		free_input_list(input_list);
	return (1);
	
}