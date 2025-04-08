/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:54:38 by aluque-v          #+#    #+#             */
/*   Updated: 2025/04/05 13:18:01 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
// # include "libft/includes/get_next_line.h"

typedef struct	s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//Reference for circular list starting point, double linked
typedef struct s_ring
{
	struct s_node	*head;
	size_t			size;
}	t_ring;

t_ring	*init_ring(void);
t_node	*create_node(int value);
void	add_back(t_ring *ring, t_node *node);
void	add_front(t_ring *ring, t_node *node);
void	extract_node(t_ring *ring, t_node *node);
int		get_position(t_ring *ring, t_node *node);
t_node	*get_max(t_ring *ring);
t_node	*get_min(t_ring *ring);
int		is_sorted(t_ring *ring);
void	sa(t_ring *a);
void	sb(t_ring *b);
void	ss(t_ring *a, t_ring *b);
void	pa(t_ring *a, t_ring *b);
void	pb(t_ring *a, t_ring *b);
void	ra(t_ring *a);
void	rb(t_ring *b);
void	rr(t_ring *a, t_ring *b);
void	rra(t_ring *a);
void	rrb(t_ring *b);
void	rrr(t_ring *a, t_ring *b);
//NOT DONE
void	free_ring(t_ring *ring);
t_node	*find_node(t_ring *ring, int value);
int		count_moves(t_ring *ring, t_node *node, int target_pos);

#endif
