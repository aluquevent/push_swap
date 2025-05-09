/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:31:48 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:44:44 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Optimizes rotation operations by calculating combined moves.
 * 
 * This function identifies opportunities for performing combined rotations (rr)
 * and reverse rotations (rrr) to reduce the total number of operations. It 
 * updates the cost structure with optimized operation counts.
 * 
 * @param cost Pointer to the cost structure to be optimized
 */
static void	calculate_combined_rotations(t_cost *cost)
{
	if (cost->ra <= cost->rb)
		cost->rr = cost->ra;
	else
		cost->rr = cost->rb;
	if (cost->rra <= cost->rrb)
		cost->rrr = cost->rra;
	else
		cost->rrr = cost->rrb;
	if (cost->rr > 0)
	{
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	if (cost->rrr > 0)
	{
		cost->rra -= cost->rrr;
		cost->rrb -= cost->rrr;
	}
}

/**
 * Calculates the cost of moving an element from ring b to its target position
 * in ring a.
 * 
 * This function computes the number of operations needed to position both rings
 * correctly for transferring the element at the specified position in ring b
 * to its target position in ring a. It optimizes by using combined rotations
 * where possible.
 * 
 * @param a Pointer to the destination ring structure
 * @param b Pointer to the source ring structure
 * @param pos_b The position in ring b of the element to be moved
 * 
 * @return t_cost The cost structure containing all operation counts and the
 *         total cost
 */
t_cost	calculate_cost(t_ring *a, t_ring *b, size_t pos_b)
{
	t_cost	cost;
	t_node	*current;
	size_t	target_pos;
	int		i;

	init_cost(&cost);
	current = b->head;
	i = -1;
	while (++i < (int)pos_b)
		current = current->next;
	target_pos = (size_t)find_target_position(a, current->value);
	cost.value = current->value;
	if (target_pos <= a->size / 2)
		cost.ra = target_pos;
	else
		cost.rra = a->size - target_pos;
	if (pos_b <= b->size / 2)
		cost.rb = pos_b;
	else
		cost.rrb = b->size - pos_b;
	calculate_combined_rotations(&cost);
	cost.total = cost.ra + cost.rb + cost.rr + cost.rra + cost.rrb + cost.rrr
		+ 1;
	return (cost);
}
