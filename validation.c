/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:59 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:53:57 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	find_duplicate(int analized, int num1, char **argv)
{
	int	j;
	int	num2;

	j = 1;
	while (j < analized)
	{
		num2 = ft_atoi(argv[j]);
		if (num1 == num2)
			return (1);
		j++;
	}
	return (0);
}
int	validate_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	num1;

	i = 1;
	while (i < argc)
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
		if (find_duplicate(i, num1, argv))
			return (0);
		i++;
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
