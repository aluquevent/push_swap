/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:59:40 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:42:13 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Creates a new node with the specified value.
 * 
 * This function allocates memory for a new node, initializes it with the given
 * value, and sets its next and prev pointers to itself (as it's initially a
 * single-node ring).
 * 
 * @param value The integer value to store in the node
 * 
 * @return Pointer to the newly created node, or NULL if memory allocation fails
 */
t_node	*create_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = new;
	new->next = new;
	return (new);
}

/**
 * Adds a node to the back of the ring.
 * 
 * This function inserts the given node at the end of the ring, maintaining
 * the circular structure. It handles special cases for empty rings and
 * single-node rings.
 * 
 * @param ring Pointer to the ring structure
 * @param node Pointer to the node to be added
 */
void	add_back(t_ring *ring, t_node *node)
{
	t_node	*last_node;

	if (!ring || !node)
		return ;
	if (ring->size == 0)
		ring->head = node;
	else if (ring->size == 1)
	{
		node->next = ring->head;
		node->prev = ring->head;
		ring->head->next = node;
		ring->head->prev = node;
	}
	else
	{
		last_node = ring->head->prev;
		last_node->next = node;
		node->prev = last_node;
		node->next = ring->head;
		ring->head->prev = node;
	}
	ring->size++;
}

/**
 * Adds a node to the front of the ring.
 * 
 * This function inserts the given node at the beginning of the ring,
 * maintaining the circular structure. It handles special cases for empty rings
 * and updates the head pointer accordingly.
 * 
 * @param ring Pointer to the ring structure
 * @param node Pointer to the node to be added
 */
void	add_front(t_ring *ring, t_node *node)
{
	t_node	*last_node;

	if (!ring || !node)
		return ;
	if (ring->size == 0)
	{
		ring->head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		last_node = ring->head->prev;
		node->next = ring->head;
		node->prev = last_node;
		last_node->next = node;
		ring->head->prev = node;
		ring->head = node;
	}
	ring->size++;
}

/**
 * Removes a node from the ring without freeing it.
 * 
 * This function removes the specified node from the ring, updating the
 * necessary pointers to maintain the circular structure. It handles special
 * cases such as removing the head node or the last node in the ring.
 * 
 * @param ring Pointer to the ring structure
 * @param node Pointer to the node to be extracted
 */
void	extract_node(t_ring *ring, t_node *node)
{
	if (!ring || !node || ring->size == 0)
		return ;
	if (ring->size == 1)
	{
		ring->head = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (ring->head == node)
			ring->head = node->next;
	}
	ring->size--;
}
