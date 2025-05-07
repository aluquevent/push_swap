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

void	sort_two(t_ring *a)
{
	if (a->head->value > a->head->next->value)
		do_sa(a);
}

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
