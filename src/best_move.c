/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:31:41 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:38:07 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

t_cost	find_best_move(t_ring *a, t_ring *b)
{
	t_cost	min_cost;
	t_cost	current_cost;
	size_t	i;

	min_cost.total = INT_MAX;
	min_cost.ra = 0;
	min_cost.rb = 0;
	min_cost.rr = 0;
	min_cost.rra = 0;
	min_cost.rrb = 0;
	min_cost.rrr = 0;
	min_cost.value = 0;
	i = 0;
	while (i < b->size)
	{
		current_cost = calculate_cost(a, b, i);
		if (current_cost.total < min_cost.total)
			min_cost = current_cost;
		i++;
	}
	return (min_cost);
}

static void	execute_combined_moves(t_ring *a, t_ring *b, t_cost *cost)
{
	int	i;

	i = 0;
	while (i < cost->rr)
	{
		do_rr(a, b);
		i++;
	}
	i = 0;
	while (i < cost->rrr)
	{
		do_rrr(a, b);
		i++;
	}
}

static void	execute_a_moves(t_ring *a, t_cost *cost)
{
	int	i;

	i = 0;
	while (i < cost->ra)
	{
		do_ra(a);
		i++;
	}
	i = 0;
	while (i < cost->rra)
	{
		do_rra(a);
		i++;
	}
}

static void	execute_b_moves(t_ring *b, t_cost *cost)
{
	int	i;

	i = 0;
	while (i < cost->rb)
	{
		do_rb(b);
		i++;
	}
	i = 0;
	while (i < cost->rrb)
	{
		do_rrb(b);
		i++;
	}
}

void	execute_moves(t_ring *a, t_ring *b, t_cost cost)
{
	execute_combined_moves(a, b, &cost);
	execute_a_moves(a, &cost);
	execute_b_moves(b, &cost);
	do_pa(b, a);
}
