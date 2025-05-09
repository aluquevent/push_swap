/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_do_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:25 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:43:57 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Executes the 'ra' operation and updates the operation counter.
 * 
 * This function rotates stack a upward (first element becomes last), prints
 * the operation name to stdout, and increments the corresponding operation
 * counter.
 *
 * @param a Pointer to stack a
 */
void	do_ra(t_ring *a)
{
	rotate(a, false);
	ft_printf("ra\n");
	g_ops.ra++;
}

/**
 * Executes the 'rb' operation and updates the operation counter.
 * 
 * This function rotates stack b upward (first element becomes last), prints
 * the operation name to stdout, and increments the corresponding operation
 * counter.
 *
 * @param b Pointer to stack b
 */
void	do_rb(t_ring *b)
{
	rotate(b, false);
	ft_printf("rb\n");
	g_ops.rb++;
}

/**
 * Executes the 'rra' operation and updates the operation counter.
 * 
 * This function rotates stack a downward (last element becomes first), prints
 * the operation name to stdout, and increments the corresponding operation
 * counter.
 *
 * @param a Pointer to stack a
 */
void	do_rra(t_ring *a)
{
	rotate(a, true);
	ft_printf("rra\n");
	g_ops.rra++;
}

/**
 * Executes the 'rrb' operation and updates the operation counter.
 * 
 * This function rotates stack b downward (last element becomes first), prints
 * the operation name to stdout, and increments the corresponding operation
 * counter.
 *
 * @param b Pointer to stack b
 */
void	do_rrb(t_ring *b)
{
	rotate(b, true);
	ft_printf("rrb\n");
	g_ops.rrb++;
}
