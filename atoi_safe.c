/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loasaad <loasaad@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:12:00 by loasaad           #+#    #+#             */
/*   Updated: 2025/09/05 18:18:34 by loasaad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	skip_space_sign(const char *str, int *i)
{
	int	sign;
	
	while ((str[*i] <= 13 && str[*i] >= 9) || str[*i] == ' ')
		(*i)++;
	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	atoi_safe(const char *str, int *result)
{
	int		i;
	int		sign;
	long	numb;

	i = 0;
	numb = 0;
	sign = skip_space_sign(str, &i);
	if (str[i] < '0' || str[i] > '9')
		return (0);
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

