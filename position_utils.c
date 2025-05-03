/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:36 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:43:41 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	find_target_position(t_ring *a, int value)
{
	t_node	*current;
	t_node	*min_node;
	int		target_pos;
	int		i;
	int		closest_larger_value;
	int		closest_larger_pos;

	if (!a || a->size == 0)
		return (0);
	current = a->head;
	closest_larger_value = INT_MAX;
	closest_larger_pos = -1;
	i = 0;
	while (i < a->size)
	{
		if (current->value > value && current->value < closest_larger_value)
		{
			closest_larger_value = current->value;
			closest_larger_pos = i;
		}
		current = current->next;
		i++;
	}
	if (closest_larger_pos != -1)
		return (closest_larger_pos);
	min_node = get_min(a);
	return (get_position(a, min_node));
}

void	final_rotation(t_ring *a)
{
	t_node	*min_node;
	int		min_pos;

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
