#include "operations.h"

int	main(int argc, char **argv)
{
	t_ring	*stack_a;
	t_ring	*stack_b;
	t_ops	ops;

	if (argc < 2)
	{
		ft_printf("Error: Not enough arguments\n");
		return (1);
	}
	if (!validate_args(argc, argv))
	{
		ft_printf("Error: Invalid arguments\n");
		return (1);
	}

	stack_a = init_ring_a(argc, argv);
	stack_b = init_ring();
	if (!stack_a || !stack_b)
	{
		if (stack_a)
			free_ring(stack_a);
		if (stack_b)
			free_ring(stack_b);
		ft_printf("Error: Memory allocation failed\n");
		return (1);
	}

	// Print initial state
	ft_printf("Initial state:\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	// Sort the stack
	ops = init_ops_counter();
	if (is_sorted(stack_a))
		ft_printf("Stack is already sorted\n");
	else
		sort_stack(stack_a, stack_b);

	// Print final state
	ft_printf("\nFinal state:\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');

	// Print operations summary
	print_ops_summary(&ops);

	// Free memory
	free_ring(stack_a);
	free_ring(stack_b);
	return (0);
}