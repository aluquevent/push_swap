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

#include "push_swap.h"

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

void	ss(t_ring *a, t_ring *b)
{
	swap(a);
	swap(b);
}

void	push(t_ring *origin, t_ring *dest)
{
	t_node	*node_to_push;

	if (!origin || origin->size == 0)
		return ;
	node_to_push = origin->head;
	extract_node(origin, node_to_push);
	add_front(dest, node_to_push);
}

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
