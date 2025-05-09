/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:59 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:44:26 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Processes a single string argument containing multiple numbers.
 * 
 * This function splits a space-separated string into an array of individual
 * number strings for further processing.
 *
 * @param arg The string containing space-separated numbers
 *
 * @return An array of strings, each containing a single number
 */
static char	**handle_single_arg(char *arg)
{
	char	**data;

	data = ft_split(arg, ' ');
	return (data);
}

/**
 * Processes multiple command-line arguments.
 * 
 * This function creates an array of strings from the command-line arguments,
 * skipping the program name (argv[0]).
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 *
 * @return An array of strings containing the arguments
 */
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

/**
 * Frees memory allocated for the string array.
 * 
 * This function properly deallocates memory based on whether the array was
 * created from a single argument (requiring each string to be freed) or
 * multiple arguments (only requiring the array itself to be freed).
 *
 * @param data The array of strings to be freed
 * @param single_arg Flag indicating if the array came from a single argument
 */
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

/**
 * Validates and processes command-line arguments.
 * 
 * This function handles both single-string and multiple-string input formats,
 * validates the arguments, and converts them to an array of integers.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @param elements Pointer to store the number of valid elements
 *
 * @return An array of integers if validation succeeds, NULL otherwise
 */
int	*validate_args(int argc, char **argv, size_t *elements)
{
	char	**data;
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
