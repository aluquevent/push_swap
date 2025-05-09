/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:40:59 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:41:07 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Initializes an empty ring structure.
 * 
 * This function allocates memory for a new ring structure and initializes its
 * members. The head pointer is set to NULL and size to 0.
 * 
 * @return Pointer to the newly allocated and initialized ring structure, or
 *         NULL if memory allocation fails
 */
t_ring	*init_ring(void)
{
	t_ring	*ring;

	ring = (t_ring *)malloc(sizeof(t_ring));
	if (!ring)
		return (NULL);
	ring->head = NULL;
	ring->size = 0;
	return (ring);
}

/**
 * Initializes ring a with the provided array of numbers.
 * 
 * This function creates a new ring structure and populates it with nodes
 * containing the values from the provided array. Each value is added to the
 * back of the ring.
 * 
 * @param nums Array of integers to populate the ring with
 * @param elements Number of elements in the array
 * 
 * @return Pointer to the newly created and populated ring structure, or
 *         NULL if memory allocation fails
 */
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

/**
 * Initializes a cost structure with zero values.
 * 
 * This function sets all operation counters in the cost structure to zero,
 * preparing it for cost calculation.
 * 
 * @param cost Pointer to the cost structure to be initialized
 */
void	init_cost(t_cost *cost)
{
	cost->ra = 0;
	cost->rb = 0;
	cost->rr = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rrr = 0;
	cost->total = 0;
	cost->value = 0;
}

/**
 * Initializes both stack a and stack b for the sorting algorithm.
 * 
 * This function creates and initializes both stacks needed for the algorithm.
 * Stack a is populated with the input numbers, while stack b is initialized
 * as empty. If any allocation fails, it performs cleanup and returns an error.
 * 
 * @param stack_a Pointer to where the stack a pointer should be stored
 * @param stack_b Pointer to where the stack b pointer should be stored
 * @param nums Array of integers to populate stack a with
 * @param elements Number of elements in the array
 * 
 * @return 1 on success, 0 on failure
 */
int	init_stacks(t_ring **stack_a, t_ring **stack_b, int *nums, size_t elements)
{
	*stack_a = init_ring_a(nums, elements);
	*stack_b = init_ring();
	if (!*stack_a || !*stack_b)
	{
		if (*stack_a)
			free_ring(*stack_a);
		if (*stack_b)
			free_ring(*stack_b);
		ft_printf("Error: Memory allocation failed\n");
		return (0);
	}
	return (1);
}
