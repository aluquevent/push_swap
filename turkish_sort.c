/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:56 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:45:14 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	turkish_sort(t_ring *a, t_ring *b)
{
	t_cost	best_move;
	int		original_size;

	original_size = a->size;
	if (original_size <= 5)
	{
		optimize_small_sort(a, b);
		return ;
	}
	optimized_push_initial(a, b);
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 2)
		sort_two(a);
	while (b->size > 0)
	{
		best_move = find_best_move(a, b);
		execute_moves(a, b, best_move);
	}
	final_rotation(a);
}

static void	prepare_stacks(t_ring *a, t_ring *b)
{
	optimized_push_initial(a, b);
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 2)
		sort_two(a);
}

static void	optimize_return(t_ring *a, t_ring *b)
{
	t_cost	best_move;

	while (b->size > 0)
	{
		best_move = find_best_move(a, b);
		execute_moves(a, b, best_move);
	}
}
