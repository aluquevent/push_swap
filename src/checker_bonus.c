/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:18:00 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 16:19:45 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operations.h"
#include "../libft/includes/get_next_line.h"

int	check_arguments(int argc, char **argv, size_t *elements, int **nums)
{
	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments\n");
		return (0);
	}
	*nums = validate_args(argc, argv, elements);
	if (*nums == NULL)
	{
		ft_printf("Error: Invalid arguments\n");
		return (0);
	}
	return (1);
}

/**
 * Frees all allocated memory for the program.
 * 
 * This function ensures all dynamically allocated memory is properly freed
 * before the program exits, preventing memory leaks.
 *
 * @param nums Pointer to the array of integers
 * @param stack_a Pointer to stack a
 * @param stack_b Pointer to stack b
 */
static void	clean_resources(int *nums, t_ring *stack_a, t_ring *stack_b)
{
	free(nums);
	free_ring(stack_a);
	free_ring(stack_b);
}

static int	execute_operation(char *instruction, t_ring *a, t_ring *b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate(a, false);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate(b, false);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(a, b, false);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rotate(a, true);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rotate(b, true);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rr(a, b, true);
	else
		return (0);
	return (1);
}

static int	read_and_execute(t_ring *a, t_ring *b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!execute_operation(instruction, a, b))
		{
			free(instruction);
			return (0);
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	return (1);
}

static int	check_result(t_ring *a, t_ring *b)
{
	if (b->size > 0)
		return (0);
	return (is_sorted(a));
}

int	main (int argc, char **argv)
{
	t_ring	*stack_a;
	t_ring	*stack_b;
	size_t	elements;
	int		*nums;

	if (!check_arguments(argc, argv, &elements, &nums))
	{
		ft_printf("Error\n");
		return (1);
	}
		if (!init_stacks(&stack_a, &stack_b, nums, elements))
	{
		ft_printf("Error\n");
		free(nums);
		return (1);
	}
	if (is_sorted(stack_a))
		ft_printf("Already sorted\n");
	else
		read_and_execute(stack_a, stack_b);
	if (check_result(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_resources(nums, stack_a, stack_b);
	return (0);
}
