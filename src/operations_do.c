/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_do.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:28 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:43:14 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Executes the 'sa' operation and updates the operation counter.
 * 
 * This function swaps the top two elements of stack a, prints the operation
 * name to stdout, and increments the corresponding operation counter.
 *
 * @param a Pointer to stack a
 */
void	do_sa(t_ring *a)
{
	swap(a);
	ft_printf("sa\n");
	g_ops.sa++;
}

/**
 * Executes the 'sb' operation and updates the operation counter.
 * 
 * This function swaps the top two elements of stack b, prints the operation
 * name to stdout, and increments the corresponding operation counter.
 *
 * @param b Pointer to stack b
 */
void	do_sb(t_ring *b)
{
	swap(b);
	ft_printf("sb\n");
	g_ops.sb++;
}

/**
 * Executes the 'ss' operation and updates the operation counter.
 * 
 * This function swaps the top two elements of both stacks simultaneously,
 * prints the operation name to stdout, and increments the corresponding
 * operation counter.
 *
 * @param a Pointer to stack a
 * @param b Pointer to stack b
 */
void	do_ss(t_ring *a, t_ring *b)
{
	ss(a, b);
	ft_printf("ss\n");
	g_ops.ss++;
}

/**
 * Executes the 'pa' operation and updates the operation counter.
 * 
 * This function pushes the top element from stack b to stack a, prints the
 * operation name to stdout, and increments the corresponding operation counter.
 *
 * @param b Pointer to source stack b
 * @param a Pointer to destination stack a
 */
void	do_pa(t_ring *b, t_ring *a)
{
	push(b, a);
	ft_printf("pa\n");
	g_ops.pa++;
}

/**
 * Executes the 'pb' operation and updates the operation counter.
 * 
 * This function pushes the top element from stack a to stack b, prints the
 * operation name to stdout, and increments the corresponding operation counter.
 *
 * @param a Pointer to source stack a
 * @param b Pointer to destination stack b
 */
void	do_pb(t_ring *a, t_ring *b)
{
	push(a, b);
	ft_printf("pb\n");
	g_ops.pb++;
}
