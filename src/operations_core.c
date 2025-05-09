/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:23 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:43:04 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Swaps the top two elements of a ring.
 * 
 * This function exchanges the positions of the first and second elements in
 * the ring, updating all necessary pointers to maintain the circular structure.
 * No action is taken if the ring has fewer than 2 elements.
 *
 * @param ring Pointer to the ring structure
 */
void	swap(t_ring *ring)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*last_node;
	t_node	*third_node;

	if (!ring || ring->size < 2)
		return ;
	top_node = ring->head;
	second_node = top_node->next;
	last_node = top_node->prev;
	third_node = second_node->next;
	second_node->prev = last_node;
	last_node->next = second_node;
	top_node->next = third_node;
	third_node->prev = top_node;
	top_node->prev = second_node;
	second_node->next = top_node;
	ring->head = second_node;
}

/**
 * Swaps the top elements of both rings simultaneously.
 * 
 * This function performs the swap operation on both rings a and b in a single
 * step, which counts as a single operation in the algorithm.
 *
 * @param a Pointer to the first ring structure
 * @param b Pointer to the second ring structure
 */
void	ss(t_ring *a, t_ring *b)
{
	swap(a);
	swap(b);
}

/**
 * Moves the top element from one ring to the top of another ring.
 * 
 * This function removes the head node from the origin ring and adds it to
 * the front of the destination ring. No action is taken if the origin ring
 * is empty.
 *
 * @param origin Pointer to the source ring structure
 * @param dest Pointer to the destination ring structure
 */
void	push(t_ring *origin, t_ring *dest)
{
	t_node	*node_to_push;

	if (!origin || origin->size == 0)
		return ;
	node_to_push = origin->head;
	extract_node(origin, node_to_push);
	add_front(dest, node_to_push);
}

/**
 * Rotates the elements of a ring.
 * 
 * This function shifts all elements in the ring by one position. If reverse
 * is false, the first element becomes the last. If reverse is true, the last
 * element becomes the first. No action is taken if the ring has fewer than 2
 * elements.
 *
 * @param ring Pointer to the ring structure
 * @param reverse Boolean flag indicating direction (false for ra/rb, true for
 *                rra/rrb)
 */
void	rotate(t_ring *ring, bool reverse)
{
	if (!reverse)
	{
		if (!ring || ring->size < 2)
			return ;
		ring->head = ring->head->next;
	}
	else
	{
		if (!ring || ring->size < 2)
			return ;
		ring->head = ring->head->prev;
	}
}

/**
 * Rotates both rings simultaneously in the same direction.
 * 
 * This function performs rotation on both rings a and b in a single step,
 * which counts as a single operation in the algorithm. The direction is
 * determined by the reverse parameter.
 *
 * @param a Pointer to the first ring structure
 * @param b Pointer to the second ring structure
 * @param reverse Boolean flag indicating direction (false for rr, true for rrr)
 */
void	rr(t_ring *a, t_ring *b, bool reverse)
{
	if (!reverse)
	{
		rotate(a, false);
		rotate(b, false);
	}
	else
	{
		rotate(a, true);
		rotate(b, true);
	}
}
