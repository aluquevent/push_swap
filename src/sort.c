/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:53 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:43:54 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Sorts a ring containing exactly 2 elements.
 * 
 * This function checks if the 2 elements are out of order and swaps them
 * if necessary, using a single operation.
 *
 * @param a Pointer to the ring structure
 */
void	sort_two(t_ring *a)
{
	if (a->head->value > a->head->next->value)
		do_sa(a);
}

/**
 * Sorts a ring containing exactly 3 elements.
 * 
 * This function implements an optimized algorithm for sorting 3 elements
 * using the minimum number of operations. It analyzes the current arrangement
 * and applies the appropriate sequence of operations.
 *
 * @param a Pointer to the ring structure
 */
void	sort_three(t_ring *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first > second && second < third && first < third)
		do_sa(a);
	else if (first > second && second > third)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (first > second && second < third && first > third)
		do_ra(a);
	else if (first < second && second > third && first < third)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (first < second && second > third && first > third)
		do_rra(a);
}

/**
 * Main sorting function that selects the appropriate algorithm.
 * 
 * This function initializes the operation counter and then selects and applies
 * the most appropriate sorting algorithm based on the number of elements in
 * the stack.
 *
 * @param a Pointer to the primary ring structure
 * @param b Pointer to the auxiliary ring structure
 */
void	sort_stack(t_ring *a, t_ring *b)
{
	if (!a || !b)
		return ;
	init_ops_counter();
	if (is_sorted(a) || a->size <= 1)
		return ;
	else if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else
		turkish_sort(a, b);
}
