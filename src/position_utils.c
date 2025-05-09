/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:36 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:49:23 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Finds the target position in ring a for a value from ring b.
 * 
 * This function determines where in ring a a value from ring b should be
 * placed to maintain sorted order. It looks for the closest larger value in
 * ring a, or if the value is the largest, it targets the position after the
 * minimum value.
 *
 * @param a Pointer to the destination ring structure
 * @param value The value from ring b to find a position for
 *
 * @return The optimal position in ring a for the specified value
 */
int	find_target_position(t_ring *a, int value)
{
	t_node	*current;
	t_node	*min_node;
	int		i;
	int		closest_larger_value;
	int		closest_larger_pos;

	if (!a || a->size == 0)
		return (0);
	current = a->head;
	closest_larger_value = INT_MAX;
	closest_larger_pos = -1;
	i = -1;
	while (++i < (int)a->size)
	{
		if (current->value > value && current->value < closest_larger_value)
		{
			closest_larger_value = current->value;
			closest_larger_pos = i;
		}
		current = current->next;
	}
	if (closest_larger_pos != -1)
		return (closest_larger_pos);
	min_node = get_min(a);
	return (get_position(a, min_node));
}

/**
 * Performs the final rotation to ensure the minimum value is at the top.
 * 
 * After all elements have been sorted and moved to ring a, this function
 * rotates the ring so that the smallest element is at the head position,
 * completing the sort in ascending order.
 *
 * @param a Pointer to the ring structure to be adjusted
 */
void	final_rotation(t_ring *a)
{
	t_node	*min_node;
	size_t	min_pos;

	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	if (min_pos <= a->size / 2)
	{
		while (min_pos > 0)
		{
			do_ra(a);
			min_pos--;
		}
	}
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos > 0)
		{
			do_rra(a);
			min_pos--;
		}
	}
}
