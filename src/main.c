/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:43 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:43:41 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Validates command-line arguments and converts them to integers.
 * 
 * This function checks if there are enough arguments and validates them using
 * the validate_args function. If successful, it returns the converted integers.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @param elements Pointer to store the number of elements
 * @param nums Pointer to store the array of integers
 *
 * @return 1 if arguments are valid, 0 otherwise
 */
static int	check_arguments(int argc, char **argv, size_t *elements, int **nums)
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
 * Prints the contents of a stack for debugging purposes.
 * 
 * This function displays all values in the specified ring, along with its
 * size. It formats the output with the stack name for clarity.
 *
 * @param ring Pointer to the ring structure to be printed
 * @param stack_name Character identifier for the stack ('a' or 'b')
 */
// static void	print_stack(t_ring *ring, char stack_name)
// {
// 	t_node	*current;
// 	size_t	i;
//
// 	if (!ring || ring->size == 0)
// 	{
// 		ft_printf("Stack %c: [empty]\n", stack_name);
// 		return ;
// 	}
// 	ft_printf("Stack %c: [", stack_name);
// 	current = ring->head;
// 	i = 0;
// 	while (i < ring->size)
// 	{
// 		ft_printf("%d", current->value);
// 		if (i < ring->size - 1)
// 			ft_printf(", ");
// 		current = current->next;
// 		i++;
// 	}
// 	ft_printf("] (size: %d)\n", ring->size);
// }

/**
 * Prints the current state of both stacks with a descriptive message.
 * 
 * This function displays the contents of both stacks along with a message
 * indicating the current stage of the algorithm.
 *
 * @param stack_a Pointer to stack a
 * @param stack_b Pointer to stack b
 * @param message The descriptive message to display
 */
// static void	print_states(t_ring *stack_a, t_ring *stack_b, char *message)
// {
// 	ft_printf("%s\n", message);
// 	print_stack(stack_a, 'a');
// 	print_stack(stack_b, 'b');
// }

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

/**
 * Main entry point for the push_swap program.
 * 
 * This function orchestrates the entire sorting process: it validates input,
 * initializes data structures, sorts the stack if needed, and cleans up
 * resources before exiting.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 *
 * @return 0 on successful execution, 1 on error
 */
int	main(int argc, char **argv)
{
	t_ring	*stack_a;
	t_ring	*stack_b;
	size_t	elements;
	int		*nums;

	if (!check_arguments(argc, argv, &elements, &nums))
		return (1);
	if (!init_stacks(&stack_a, &stack_b, nums, elements))
	{
		free(nums);
		return (1);
	}
	// print_states(stack_a, stack_b, "\nInitial state: \n");
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	// print_ops_summary();
	// print_states(stack_a, stack_b, "\nFinal state: \n");
	clean_resources(nums, stack_a, stack_b);
	return (0);
}
