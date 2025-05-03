/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:43 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:46:04 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	print_stack(t_ring *ring, char stack_name)
{
	t_node	*current;
	int		i;

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

int	main(int argc, char **argv)
{
	t_ring	*stack_a;
	t_ring	*stack_b;

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
	ft_printf("Initial state:\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	if (is_sorted(stack_a))
		ft_printf("Stack is already sorted\n");
	else
		sort_stack(stack_a, stack_b);
	ft_printf("\nFinal state:\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	free_ring(stack_a);
	free_ring(stack_b);
	return (0);
}
