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

#include "push_swap.h"

size_t	get_position(t_ring *ring, t_node *node)
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