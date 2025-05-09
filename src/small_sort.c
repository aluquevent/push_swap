/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:50 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:44:50 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Rotates a ring until the specified position is at the top.
 * 
 * This function determines whether to use rotate or reverse rotate operations
 * based on which would require fewer operations to bring the target position
 * to the head of the ring.
 *
 * @param a Pointer to the ring structure
 * @param pos The target position to bring to the top
 */
void	rotate_to_pos(t_ring *a, int pos)
{
	int	size;
	int	i;

	size = a->size;
	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			do_ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			do_rra(a);
			i++;
		}
	}
}

/**
 * Optimized sorting algorithm for exactly 4 elements.
 * 
 * This function implements a specialized approach for sorting 4 elements:
 * it moves the minimum value to ring b, sorts the remaining 3 elements, and
 * then brings back the minimum to the top of ring a.
 *
 * @param a Pointer to the primary ring structure
 * @param b Pointer to the auxiliary ring structure
 */
static void	optimize_four(t_ring *a, t_ring *b)
{
	t_node	*min_node;
	int		min_pos;

	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	rotate_to_pos(a, min_pos);
	do_pb(a, b);
	sort_three(a);
	do_pa(b, a);
}

/**
 * Optimized sorting algorithm for exactly 5 elements.
 * 
 * This function implements a specialized approach for sorting 5 elements:
 * it moves the two minimum values to ring b, sorts the remaining 3 elements,
 * and then brings back the minimum values to the top of ring a.
 *
 * @param a Pointer to the primary ring structure
 * @param b Pointer to the auxiliary ring structure
 */
static void	optimize_five(t_ring *a, t_ring *b)
{
	t_node	*min_node;
	int		min_pos;

	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	rotate_to_pos(a, min_pos);
	do_pb(a, b);
	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	rotate_to_pos(a, min_pos);
	do_pb(a, b);
	sort_three(a);
	do_pa(b, a);
	do_pa(b, a);
}

/**
 * Selects and applies the appropriate small sorting algorithm.
 * 
 * This function determines the best sorting approach based on the number of
 * elements in ring a, choosing between specialized algorithms for 4 or 5
 * elements.
 *
 * @param a Pointer to the primary ring structure
 * @param b Pointer to the auxiliary ring structure
 */
void	optimize_small_sort(t_ring *a, t_ring *b)
{
	if (a->size == 4)
		optimize_four(a, b);
	else if (a->size == 5)
		optimize_five(a, b);
}
