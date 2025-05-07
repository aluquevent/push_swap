/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_initial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:38 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:43:54 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Esta función determina si un número 
// es de la mitad superior o inferior del rango
static int	is_in_upper_half(t_ring *a, int value)
{
	t_node	*min_node;
	t_node	*max_node;
	int		min_val;
	int		max_val;
	int		median;

	min_node = get_min(a);
	max_node = get_max(a);
	min_val = min_node->value;
	max_val = max_node->value;
	median = min_val + (max_val - min_val) / 2;
	if (value > median)
		return (1);
	return (0);
}

static int	find_best_push_pos(t_ring *a)
{
	size_t	i;
	int		best_pos;
	int		min_cost;
	t_node	*current;
	int		cost;

	best_pos = 0;
	min_cost = INT_MAX;
	i = 0;
	current = a->head;
	while (i < a->size)
	{
		if (i <= a->size / 2)
			cost = i;
		else
			cost = a->size - i;
		if (cost < min_cost)
		{
			min_cost = cost;
			best_pos = i;
		}
		current = current->next;
		i++;
	}
	return (best_pos);
}

static void	push_to_chunks(t_ring *a, t_ring *b, int to_push)
{
	int	pushed;
	int	is_upper;

	pushed = 0;
	while (pushed < to_push / 2)
	{
		is_upper = is_in_upper_half(a, a->head->value);
		if (!is_upper)
		{
			do_pb(a, b);
			pushed++;
		}
		else
			do_ra(a);
		if (pushed == 0 && a->head == a->head->next->next->next)
		{
			do_pb(a, b);
			pushed++;
		}
	}
}

static void	push_remaining(t_ring *a, t_ring *b)
{
	int	best_pos;

	while (a->size > 3)
	{
		best_pos = find_best_push_pos(a);
		rotate_to_pos(a, best_pos);
		do_pb(a, b);
	}
}

void	optimized_push_initial(t_ring *a, t_ring *b)
{
	int	elements_to_push;

	if (a->size <= 5)
	{
		while (a->size > 3)
			do_pb(a, b);
		return ;
	}
	elements_to_push = a->size - 3;
	push_to_chunks(a, b, elements_to_push);
	push_remaining(a, b);
}
