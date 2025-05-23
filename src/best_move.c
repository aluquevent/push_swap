/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:31:41 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:38:07 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Finds the optimal move with minimal cost by evaluating all positions in 
 * ring b.
 * 
 * This function iterates through each position in ring b and calculates the
 * associated cost of moving that element to its correct position in ring a.
 * It returns the move with the lowest total cost.
 * 
 * @param a Pointer to the destination ring structure
 * @param b Pointer to the source ring structure containing elements to be 
 * 			moved
 * 
 * @return t_cost The move with the minimum total cost, containing:
 *         - total: The combined cost of all operations
 *         - ra, rb, rr: Counts for rotate operations
 *         - rra, rrb, rrr: Counts for reverse rotate operations
 *         - value: The value being moved (initialized to 0)
**/
t_cost	find_best_move(t_ring *a, t_ring *b)
{
	t_cost	min_cost;
	t_cost	current_cost;
	size_t	i;

	init_cost(&min_cost);
	min_cost.total = INT_MAX;
	i = 0;
	while (i < b->size)
	{
		current_cost = calculate_cost(a, b, i);
		if (current_cost.total < min_cost.total)
			min_cost = current_cost;
		i++;
	}
	return (min_cost);
}

/**
 * Executes combined rotation operations for both rings.
 * 
 * This helper function performs the combined rotate (rr) and reverse rotate 
 * (rrr) operations as specified in the cost structure. It optimizes the 
 * sorting algorithm by performing simultaneous operations on both rings when 
 * possible.
 * 
 * @param a Pointer to the first ring structure
 * @param b Pointer to the second ring structure
 * @param cost Pointer to the cost structure containing operation counts
 */
static void	execute_combined_moves(t_ring *a, t_ring *b, t_cost *cost)
{
	int	i;

	i = 0;
	while (i < cost->rr)
	{
		do_rr(a, b);
		i++;
	}
	i = 0;
	while (i < cost->rrr)
	{
		do_rrr(a, b);
		i++;
	}
}

/**
 * Executes rotation operations specifically for ring a.
 * 
 * This helper function performs the rotate (ra) and reverse rotate (rra) 
 * operations on ring a as specified in the cost structure, after any combined
 * operations have been executed.
 * 
 * @param a Pointer to the ring a structure
 * @param cost Pointer to the cost structure containing operation counts
 */
static void	execute_a_moves(t_ring *a, t_cost *cost)
{
	int	i;

	i = 0;
	while (i < cost->ra)
	{
		do_ra(a);
		i++;
	}
	i = 0;
	while (i < cost->rra)
	{
		do_rra(a);
		i++;
	}
}

/**
 * Executes rotation operations specifically for ring b.
 * 
 * This helper function performs the rotate (rb) and reverse rotate (rrb) 
 * operations on ring b as specified in the cost structure, after any combined
 * operations have been executed.
 * 
 * @param b Pointer to the ring b structure
 * @param cost Pointer to the cost structure containing operation counts
 */
static void	execute_b_moves(t_ring *b, t_cost *cost)
{
	int	i;

	i = 0;
	while (i < cost->rb)
	{
		do_rb(b);
		i++;
	}
	i = 0;
	while (i < cost->rrb)
	{
		do_rrb(b);
		i++;
	}
}

/**
 * Executes all required moves to place one element from ring b into ring a.
 * 
 * This function coordinates the execution of all operations required to move
 * an element from ring b to its target position in ring a in the most efficient
 * way. It first performs combined operations, then ring-specific operations, 
 * and finally pushes the element from b to a.
 * 
 * @param a Pointer to the destination ring structure
 * @param b Pointer to the source ring structure
 * @param cost The cost structure containing all required operation counts
 */
void	execute_moves(t_ring *a, t_ring *b, t_cost cost)
{
	execute_combined_moves(a, b, &cost);
	execute_a_moves(a, &cost);
	execute_b_moves(b, &cost);
	do_pa(b, a);
}
