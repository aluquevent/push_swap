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

#include "push_swap.h"

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
