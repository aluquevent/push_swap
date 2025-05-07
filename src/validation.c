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
