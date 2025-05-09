/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:05 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:33:16 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Frees all memory associated with a ring structure.
 * 
 * This function releases the memory for all nodes in the ring as well as the
 * ring structure itself. It correctly handles the circular nature of the list
 * to ensure all nodes are freed exactly once.
 * 
 * @param ring Pointer to the ring structure to be freed
 */
void	free_ring(t_ring *ring)
{
	t_node	*current;
	t_node	*next;

	if (!ring)
		return ;
	if (ring->size > 0 && ring->head)
	{
		current = ring->head;
		while (ring->size--)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	free(ring);
}
