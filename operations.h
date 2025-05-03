/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:31 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/03 16:43:21 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_ops
{
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	int			total;
}				t_ops;

extern t_ops	g_ops;

void			init_ops_counter(void);
void			do_sa(t_ring *a);
void			do_sb(t_ring *b);
void			do_ss(t_ring *a, t_ring *b);
void			do_pa(t_ring *b, t_ring *a);
void			do_pb(t_ring *a, t_ring *b);
void			do_ra(t_ring *a);
void			do_rb(t_ring *b);
void			do_rr(t_ring *a, t_ring *b);
void			do_rra(t_ring *a);
void			do_rrb(t_ring *b);
void			do_rrr(t_ring *a, t_ring *b);
void			print_ops_summary(void);
