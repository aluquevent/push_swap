/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xyz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:54:38 by aluque-v          #+#    #+#             */
/*   Updated: 2025/04/30 15:55:53 by Xyz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdbool.h>
# include <limits.h>
// # include "libft/includes/get_next_line.h"

typedef struct	s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//Reference for circular list starting point, double linked
typedef struct	s_ring
{
	struct s_node	*head;
	size_t			size;
}	t_ring;

typedef struct	s_cost
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	value;
}	t_cost;

typedef struct s_ops t_ops;

t_ring	*init_ring(void);
t_ring	*init_ring_a(int argc, char **argv);
t_node	*create_node(int value);
int		validate_args(int argc, char **argv);
void	add_back(t_ring *ring, t_node *node);
void	add_front(t_ring *ring, t_node *node);
t_node	*get_max(t_ring *ring);
t_node	*get_min(t_ring *ring);
void	extract_node(t_ring *ring, t_node *node);
int		get_position(t_ring *ring, t_node *node);
int		is_sorted(t_ring *ring);
void	swap(t_ring *ring);
void	ss(t_ring *a, t_ring *b);
void	push(t_ring *origin, t_ring *dest);
void	rotate(t_ring *ring, bool reverse);
void	rr(t_ring *a, t_ring *b, bool reverse);
void	execute_moves(t_ring *a, t_ring *b, t_cost cost, t_ops *ops);
void	sort_stack(t_ring *a, t_ring *b);
void	turkish_sort(t_ring *a, t_ring *b, t_ops *ops);
void	final_rotation(t_ring *a, t_ops *ops);
t_node	*find_node(t_ring *ring, int value);
t_cost	find_best_move(t_ring *a, t_ring *b);
int		find_target_position(t_ring *a, int value);
t_cost	calculate_cost(t_ring *a, t_ring *b, int pos_b);
void	print_stack(t_ring *ring, char stack_name);
void	free_ring(t_ring *ring);
#endif
