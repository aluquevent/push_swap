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
# include <stdbool.h>
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
t_ring	*init_ring_a(int argc, char **argv);
t_node	*create_node(int value);
void	add_back(t_ring *ring, t_node *node);
void	add_front(t_ring *ring, t_node *node);
void	extract_node(t_ring *ring, t_node *node);
int		get_position(t_ring *ring, t_node *node);
t_node	*get_max(t_ring *ring);
t_node	*get_min(t_ring *ring);
int		is_sorted(t_ring *ring);
void	swap(t_ring *ring);
void	ss(t_ring *a, t_ring *b);
void	push(t_ring *origin, t_ring *dest);
void	rotate(t_ring *ring, bool reverse);
void	rr(t_ring *a, t_ring *b, bool reverse);
void	free_ring(t_ring *ring);
t_node	*find_node(t_ring *ring, int value);
int		count_moves(t_ring *ring, t_node *node, int target_pos);
void	print_stack(t_ring *ring, char stack_name);
int		validate_args(int argc, char **argv);
#endif
