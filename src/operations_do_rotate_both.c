/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_do_rotate_both.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:42:55 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:42:57 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Executes the 'rr' operation and updates the operation counter.
 * 
 * This function rotates both stacks upward simultaneously (first element
 * becomes last), prints the operation name to stdout, and increments the
 * corresponding operation counter.
 *
 * @param a Pointer to stack a
 * @param b Pointer to stack b
 */
void	do_rr(t_ring *a, t_ring *b)
{
	rr(a, b, false);
	ft_printf("rr\n");
	g_ops.rr++;
}

/**
 * Executes the 'rrr' operation and updates the operation counter.
 * 
 * This function rotates both stacks downward simultaneously (last element
 * becomes first), prints the operation name to stdout, and increments the
 * corresponding operation counter.
 *
 * @param a Pointer to stack a
 * @param b Pointer to stack b
 */
void	do_rrr(t_ring *a, t_ring *b)
{
	rr(a, b, true);
	ft_printf("rrr\n");
	g_ops.rrr++;
}
