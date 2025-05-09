/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:32:31 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:39:13 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "list.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_cost
{
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					total;
	int					value;
}	t_cost;

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
}	t_ops;

extern t_ops	g_ops;

// Basic operations
void			swap(t_ring *ring);
void			ss(t_ring *a, t_ring *b);
void			push(t_ring *origin, t_ring *dest);
void			rotate(t_ring *ring, bool reverse);
void			rr(t_ring *a, t_ring *b, bool reverse);

// Operations with output
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

// Cost functions
void			init_cost(t_cost *cost);
void			init_ops_counter(void);
void			print_ops_summary(void);
t_cost			calculate_cost(t_ring *a, t_ring *b, size_t pos_b);
t_cost			find_best_move(t_ring *a, t_ring *b);
void			execute_moves(t_ring *a, t_ring *b, t_cost cost);

#endif
