/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:43 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:43:55 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	print_stack(t_ring *ring, char stack_name)
{
	t_node	*current;
	size_t	i;

	if (!ring || ring->size == 0)
	{
		ft_printf("Stack %c: [empty]\n", stack_name);
		return ;
	}
	ft_printf("Stack %c: [", stack_name);
	current = ring->head;
	i = 0;
	while (i < ring->size)
	{
		ft_printf("%d", current->value);
		if (i < ring->size - 1)
			ft_printf(", ");
		current = current->next;
		i++;
	}
	ft_printf("] (size: %d)\n", ring->size);
}

static void	print_states(t_ring *stack_a, t_ring *stack_b, char *message)
{
	ft_printf("%s\n", message);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
}

static void	clean_resources(int *nums, t_ring *stack_a, t_ring *stack_b)
{
	free(nums);
	free_ring(stack_a);
	free_ring(stack_b);
}


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
	print_states(stack_a, stack_b, "\nInitial state: \n");

	if (is_sorted(stack_a))
		ft_printf("Stack is already sorted\n");
	else
		sort_stack(stack_a, stack_b);
	print_ops_summary();
	print_states(stack_a, stack_b, "\nFinal state: \n");
	clean_resources(nums, stack_a, stack_b);
	return (0);
}
