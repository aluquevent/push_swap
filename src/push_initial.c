/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_initial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:38 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:43:54 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Determines if a value is in the upper half of the value range in ring a.
 * 
 * This function calculates the median value in ring a and checks if the
 * given value is above this median. This is used for efficient chunking
 * during the initial push phase.
 *
 * @param a Pointer to the ring structure
 * @param value The value to check
 *
 * @return 1 if the value is in the upper half, 0 otherwise
 */
static int	is_in_upper_half(t_ring *a, int value)
{
	t_node	*min_node;
	t_node	*max_node;
	int		min_val;
	int		max_val;
	int		median;

	min_node = get_min(a);
	max_node = get_max(a);
	min_val = min_node->value;
	max_val = max_node->value;
	median = min_val + (max_val - min_val) / 2;
	if (value > median)
		return (1);
	return (0);
}

/**
 * Finds the position in ring a that requires the minimum cost to access.
 * 
 * This function calculates the cost (number of operations) required to bring
 * each position to the top of ring a, and returns the position with the 
 * minimum cost.
 *
 * @param a Pointer to the ring structure
 *
 * @return The position that requires the minimum number of operations to reach
 */
static int	find_best_push_pos(t_ring *a)
{
	size_t	i;
	int		best_pos;
	int		min_cost;
	t_node	*current;
	int		cost;

	best_pos = 0;
	min_cost = INT_MAX;
	i = 0;
	current = a->head;
	while (i < a->size)
	{
		if (i <= a->size / 2)
			cost = i;
		else
			cost = a->size - i;
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pos = i;
		}
		current = current->next;
		i++;
	}
	return (best_pos);
}

/**
 * Pushes elements from ring a to ring b in chunks.
 * 
 * This function implements a chunking strategy where approximately half of the
 * elements (primarily those in the lower half of the value range) are pushed
 * to ring b. This creates a rough partition that helps optimize the sorting.
 *
 * @param a Pointer to the source ring structure
 * @param b Pointer to the destination ring structure
 * @param to_push The total number of elements that should be pushed
 */
static void	push_to_chunks(t_ring *a, t_ring *b, int to_push)
{
	int	pushed;
	int	is_upper;

	pushed = 0;
	while (pushed < to_push / 2)
	{
		is_upper = is_in_upper_half(a, a->head->value);
		if (!is_upper)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
		if (pushed == 0 && a->head == a->head->next->next->next)
		{
			do_pb(a, b);
			pushed++;
		}
	}
}

/**
 * Pushes the remaining elements from ring a to ring b efficiently.
 * 
 * After the initial chunking, this function pushes the remaining elements
 * (except for 3) to ring b, selecting positions that minimize rotation costs.
 *
 * @param a Pointer to the source ring structure
 * @param b Pointer to the destination ring structure
 */
static void	push_remaining(t_ring *a, t_ring *b)
{
	int	best_pos;

	while (a->size > 3)
	{
		best_pos = find_best_push_pos(a);
		rotate_to_pos(a, best_pos);
		do_pb(a, b);
	}
}

/**
 * Optimizes the initial push phase of the sorting algorithm.
 * 
 * This function implements a strategy for efficiently pushing elements from
 * ring a to ring b, leaving only the 3 elements in ring a. It uses different
 * approaches based on the total number of elements.
 *
 * @param a Pointer to the source ring structure
 * @param b Pointer to the destination ring structure
 */
void	optimized_push_initial(t_ring *a, t_ring *b)
{
	int	elements_to_push;

	if (a->size <= 5)
	{
		while (a->size > 3)
			do_pb(a, b);
		return ;
	}
	elements_to_push = a->size - 3;
	push_to_chunks(a, b, elements_to_push);
	push_remaining(a, b);
}
