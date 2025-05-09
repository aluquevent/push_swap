/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:20 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:50:08 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Gets the position of a node within the ring.
 * 
 * This function searches for the specified node in the ring and returns its
 * position (0-based index).
 * 
 * @param ring Pointer to the ring structure
 * @param node Pointer to the node whose position is being queried
 * 
 * @return The position of the node in the ring, or -1 if not found or ring is
 *         empty
 */
int	get_position(t_ring *ring, t_node *node)
{
	t_node	*current;
	size_t	pos;

	if (!ring || !node || ring->size == 0)
		return (-1);
	current = ring->head;
	pos = 0;
	while (pos < ring->size)
	{
		if (current == node)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

/**
 * Finds the node with the maximum value in the ring.
 * 
 * This function traverses the entire ring to find and return the node
 * containing the highest value.
 * 
 * @param ring Pointer to the ring structure
 * 
 * @return Pointer to the node with the maximum value, or NULL if the ring is
 *         empty
 */
t_node	*get_max(t_ring *ring)
{
	t_node	*max;
	t_node	*current;
	size_t	pos;

	if (!ring || ring->size == 0)
		return (NULL);
	max = ring->head;
	current = ring->head;
	pos = 0;
	while (pos < ring->size)
	{
		if (max->value < current->value)
			max = current;
		current = current->next;
		pos++;
	}
	return (max);
}

/**
 * Finds the node with the minimum value in the ring.
 * 
 * This function traverses the entire ring to find and return the node
 * containing the lowest value.
 * 
 * @param ring Pointer to the ring structure
 * 
 * @return Pointer to the node with the minimum value, or NULL if the ring is
 *         empty
 */
t_node	*get_min(t_ring *ring)
{
	t_node	*min;
	t_node	*current;
	size_t	pos;

	if (!ring || ring->size == 0)
		return (NULL);
	min = ring->head;
	current = ring->head;
	pos = 0;
	while (pos < ring->size)
	{
		if (min->value > current->value)
			min = current;
		current = current->next;
		pos++;
	}
	return (min);
}

/**
 * Checks if the ring is sorted in ascending order.
 * 
 * This function traverses the ring to verify that each node's value is less
 * than or equal to the next node's value.
 * 
 * @param ring Pointer to the ring structure
 * 
 * @return 1 if the ring is sorted, 0 otherwise or if the ring has fewer than
 *         2 elements
 */
int	is_sorted(t_ring *ring)
{
	size_t	pos;
	t_node	*current;

	if (!ring || ring->size < 2)
		return (0);
	pos = 0;
	current = ring->head;
	while (pos < ring->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		pos++;
	}
	return (1);
}

/**
 * Finds a node with the specified value in the ring.
 * 
 * This function traverses the ring to find a node containing the given value.
 * 
 * @param ring Pointer to the ring structure
 * @param value The value to search for
 * 
 * @return Pointer to the first node found with the specified value, or NULL if
 *         not found or ring is empty
 */
t_node	*find_node(t_ring *ring, int value)
{
	t_node	*current;
	size_t	pos;

	if (!ring || ring->size == 0)
		return (NULL);
	current = ring->head;
	pos = 0;
	while (pos < ring->size)
	{
		if (current->value == value)
			return (current);
		current = current->next;
		pos++;
	}
	return (NULL);
}
