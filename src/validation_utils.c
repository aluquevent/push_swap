/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:44:34 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:46:00 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Checks if a string represents a valid integer within the INT range.
 * 
 * This function verifies that the string can be converted to an integer
 * without overflow or underflow.
 *
 * @param str The string to validate
 *
 * @return 1 if the string represents a valid integer, 0 otherwise
 */
static int	is_valid_integer(char *str)
{
	size_t		i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == 0 && result * sign < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Checks if a string represents a valid numeric format.
 * 
 * This function verifies that the string contains only digits (with an
 * optional leading sign) and that it represents a valid integer.
 *
 * @param str The string to validate
 *
 * @return 1 if the string is a valid number, 0 otherwise
 */
static int	is_valid_number(char *str)
{
	size_t		i;

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
	if (!is_valid_integer(str))
		return (0);
	return (1);
}

/**
 * Allocates memory for the integer array.
 * 
 * This function counts the number of strings in the data array and allocates
 * an appropriately sized array to hold the converted integers.
 *
 * @param data Array of strings to be converted
 * @param elements Pointer to store the number of elements
 *
 * @return A newly allocated integer array, or NULL if allocation fails
 */
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

/**
 * Checks if a number already exists in the analyzed portion of the array.
 * 
 * This function searches for duplicate values in the already processed part
 * of the integer array.
 *
 * @param analized Number of elements already processed
 * @param num The number to check for duplicates
 * @param data The array of integers
 *
 * @return 1 if a duplicate is found, 0 otherwise
 */
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

/**
 * Processes string arguments into an array of unique integers.
 * 
 * This function converts each string to an integer, validates the format, and
 * checks for duplicates. If any validation fails, it frees allocated memory
 * and returns NULL.
 *
 * @param data Array of strings to process
 * @param elements Pointer to store the number of valid elements
 *
 * @return An array of valid, unique integers, or NULL if validation fails
 */
int	*process_numbers(char **data, size_t *elements)
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
