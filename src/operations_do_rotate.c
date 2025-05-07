/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_do_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:25 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:43:10 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_ra(t_ring *a)
{
	rotate(a, false);
	ft_printf("ra\n");
	g_ops.ra++;
}

void	do_rb(t_ring *b)
{
	rotate(b, false);
	ft_printf("rb\n");
	g_ops.rb++;
}

void	do_rr(t_ring *a, t_ring *b)
{
	rr(a, b, false);
	ft_printf("rr\n");
	g_ops.rr++;
}

void	do_rra(t_ring *a)
{
	rotate(a, true);
	ft_printf("rra\n");
	g_ops.rra++;
}

void	do_rrb(t_ring *b)
{
	rotate(b, true);
	ft_printf("rrb\n");
	g_ops.rrb++;
}

void	do_rrr(t_ring *a, t_ring *b)
{
	rr(a, b, true);
	ft_printf("rrr\n");
	g_ops.rrr++;
}
