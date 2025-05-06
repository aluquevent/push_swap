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

#include "../includes/push_swap.h"

static int	is_valid_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	*convert_data_to_int(char **data, size_t *elements)
{
	size_t	i;
	int		*nums;

	i = 0;
	while (data[i])
		i++;
	nums = (int *)malloc(sizeof(int) * i);
	if (!nums)
		return (NULL);
	*elements = i;
	return (nums);
}

static int	find_duplicate(int analized, int num, int *data)
{
	int	j;
	
	j = 0;
	while (j < analized)
	{
		if (num == data[j])
			return (1);
		j++;
	}
	return (0);
}

static int	*process_numbers(char **data, size_t *elements)
{
	size_t	i;
	int		*nums;

	nums = convert_data_to_int(data, elements);
	if (!nums)
		return (NULL);
	i = 0;
	while (data[i])
	{
		if (!is_valid_number(data[i]))
		{
			free(nums);
			return (NULL);
		}
		nums[i] = ft_atoi(data[i]);
		if (find_duplicate(i, nums[i], nums))
		{
			free(nums);
			return (NULL);
		}
		i++;
	}
	return (nums);
}

static char	**handle_single_arg(char *arg)
{
	char **data;

	data = ft_split(arg, ' ');
	return (data);
}

static char	**handle_multiple_args(int argc, char **argv)
{
	size_t	i;
	char	**data;

	data = (char **)malloc(sizeof(char *) * argc);
	if (!data)
		return (NULL);
	i = 1;
	while (i < (size_t)argc)
	{
		data[i - 1] = argv[i];
		i++;
	}
	data [i - 1] = NULL;
	return (data);
}

static void	free_data(char **data, int single_arg)
{
	size_t	i;

	if (single_arg)
	{
		i = 0;
		while (data[i])
			free(data[i++]);
	}
	free (data);
}

int	*validate_args(int argc, char **argv, size_t *elements)
{
	char 	**data;
	int		*nums;
	int		single_arg;

	if (argc == 2)
	{
		data = handle_single_arg(argv[1]);
		single_arg = 1;
	}
	else
	{
		data = handle_multiple_args(argc, argv);
		single_arg = 0;
	}
	if (!data)
		return (NULL);
	nums = process_numbers(data, elements);
	free_data(data, single_arg);
	return (nums);
}


t_ring	*init_ring_a(int *nums, size_t elements)
{
	t_ring	*a;
	t_node	*new_node;
	size_t	i;

	a = init_ring();
	if (!a)
		return (NULL);
	i = 0;
	while (i < elements)
	{
		new_node = create_node(nums[i]);
		if (!new_node)
		{
			free_ring(a);
			return (NULL);
		}
		add_back(a, new_node);
		i++;
	}
	return (a);
}
