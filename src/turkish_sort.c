/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:56 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:47:48 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Prepares the stacks for the main sorting algorithm.
 * 
 * This function moves most elements from stack a to stack b in an optimized
 * manner, leaving only 2 or 3 elements in stack a which are then sorted
 * directly.
 *
 * @param a Pointer to the primary ring structure
 * @param b Pointer to the auxiliary ring structure
 */
static void	prepare_stacks(t_ring *a, t_ring *b)
{
	optimized_push_initial(a, b);
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 2)
		sort_two(a);
}

/**
 * Efficiently returns elements from stack b to stack a in sorted order.
 * 
 * This function iteratively finds the element in stack b that can be moved
 * to stack a with the minimum cost, and performs the necessary operations
 * to move it to its correct position.
 *
 * @param a Pointer to the destination ring structure
 * @param b Pointer to the source ring structure
 */
static void	optimize_return(t_ring *a, t_ring *b)
{
	t_cost	best_move;

	while (b->size > 0)
	{
		best_move = find_best_move(a, b);
		execute_moves(a, b, best_move);
	}
}

/**
 * Implements the main sorting algorithm (Turkish algorithm).
 * 
 * This function coordinates the entire sorting process for stacks with more
 * than 5 elements. It prepares the stacks, optimizes the return of elements
 * to stack a, and performs a final adjustment to ensure the minimum element
 * is at the top.
 *
 * @param a Pointer to the primary ring structure
 * @param b Pointer to the auxiliary ring structure
 */
void	turkish_sort(t_ring *a, t_ring *b)
{
	if (a->size <= 5)
	{
		optimize_small_sort(a, b);
		return ;
	}
	prepare_stacks(a, b);
	optimize_return(a, b);
	final_rotation(a);
}
