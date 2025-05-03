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

#include "push_swap.h"

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
