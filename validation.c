/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:59 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:46:34 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		num1 = ft_atoi(argv[i]);
		for (j = 1; j < i; j++)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (0);
		}
	}
	return (1);
}

t_ring	*init_ring_a(int argc, char **argv)
{
	t_ring	*a;
	t_node	*new_node;
	int		i;

	a = init_ring();
	if (!a)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
		{
			free_ring(a);
			return (NULL);
		}
		add_back(a, new_node);
	}
	return (a);
}
