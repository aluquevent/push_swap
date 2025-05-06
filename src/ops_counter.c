/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:33 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:43:38 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"

t_ops	g_ops;

void	init_ops_counter(void)
{
	g_ops.sa = 0;
	g_ops.sb = 0;
	g_ops.ss = 0;
	g_ops.pa = 0;
	g_ops.pb = 0;
	g_ops.ra = 0;
	g_ops.rb = 0;
	g_ops.rr = 0;
	g_ops.rra = 0;
	g_ops.rrb = 0;
	g_ops.rrr = 0;
	g_ops.total = 0;
}

void	print_ops_summary(void)
{
	g_ops.total = g_ops.sa + g_ops.sb + g_ops.ss + g_ops.pa + g_ops.pb
		+ g_ops.ra + g_ops.rb + g_ops.rr + g_ops.rra + g_ops.rrb + g_ops.rrr;
	ft_printf("\n=== OPERATIONS SUMMARY ===\n");
	ft_printf("sa: %d\n", g_ops.sa);
	ft_printf("sb: %d\n", g_ops.sb);
	ft_printf("ss: %d\n", g_ops.ss);
	ft_printf("pa: %d\n", g_ops.pa);
	ft_printf("pb: %d\n", g_ops.pb);
	ft_printf("ra: %d\n", g_ops.ra);
	ft_printf("rb: %d\n", g_ops.rb);
	ft_printf("rr: %d\n", g_ops.rr);
	ft_printf("rra: %d\n", g_ops.rra);
	ft_printf("rrb: %d\n", g_ops.rrb);
	ft_printf("rrr: %d\n", g_ops.rrr);
	ft_printf("Total operations: %d\n", g_ops.total);
}
