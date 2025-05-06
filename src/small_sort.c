/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:50 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:44:50 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

void	rotate_to_pos(t_ring *a, int pos)
{
	int	size;
	int	i;

	size = a->size;
	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			do_ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			do_rra(a);
			i++;
		}
	}
}

// Push inicial optimizado - envía números a B parcialmente ordenados
static void	optimize_four(t_ring *a, t_ring *b)
{
	t_node	*min_node;
	int		min_pos;

	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	rotate_to_pos(a, min_pos);
	do_pb(a, b);
	sort_three(a);
	do_pa(b, a);
}

static void	optimize_five(t_ring *a, t_ring *b)
{
	t_node	*min_node;
	int		min_pos;

	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	rotate_to_pos(a, min_pos);
	do_pb(a, b);
	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	rotate_to_pos(a, min_pos);
	do_pb(a, b);
	sort_three(a);
	do_pa(b, a);
	do_pa(b, a);
}

// Optimizar el ordenamiento para casos especiales
void	optimize_small_sort(t_ring *a, t_ring *b)
{
	if (a->size == 4)
		optimize_four(a, b);
	else if (a->size == 5)
		optimize_five(a, b);
}
