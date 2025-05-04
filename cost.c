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

#include "operations.h"

void	init_cost(t_cost *cost)
{
	cost->ra = 0;
	cost->rb = 0;
	cost->rr = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rrr = 0;
	cost->total = 0;
	cost->value = 0;
}

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

t_cost	calculate_cost(t_ring *a, t_ring *b, size_t pos_b)
{
	t_cost	cost;
	t_node	*current;
	size_t	target_pos;
	size_t	i;

	init_cost(&cost);
	current = b->head;
	i = 0;
	while (i < pos_b)
	{
		current = current->next;
		i++;
	}
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
