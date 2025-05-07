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

void	do_sa(t_ring *a)
{
	swap(a);
	ft_printf("sa\n");
	g_ops.sa++;
}

void	do_sb(t_ring *b)
{
	swap(b);
	ft_printf("sb\n");
	g_ops.sb++;
}

void	do_ss(t_ring *a, t_ring *b)
{
	ss(a, b);
	ft_printf("ss\n");
	g_ops.ss++;
}

void	do_pa(t_ring *b, t_ring *a)
{
	push(b, a);
	ft_printf("pa\n");
	g_ops.pa++;
}

void	do_pb(t_ring *a, t_ring *b)
{
	push(a, b);
	ft_printf("pb\n");
	g_ops.pb++;
}
