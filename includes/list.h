/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:38:40 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:38:46 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>

typedef struct s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct s_ring
{
	struct s_node		*head;
	size_t				size;
}						t_ring;

// Linked list managing functions
t_ring					*init_ring(void);
t_ring					*init_ring_a(int *nums, size_t elements);
t_node					*create_node(int value);
void					add_back(t_ring *ring, t_node *node);
void					add_front(t_ring *ring, t_node *node);
void					extract_node(t_ring *ring, t_node *node);
void					free_ring(t_ring *ring);

// Utils functions for lists
t_node					*get_max(t_ring *ring);
t_node					*get_min(t_ring *ring);
int						get_position(t_ring *ring, t_node *node);
t_node					*find_node(t_ring *ring, int value);
int						is_sorted(t_ring *ring);

#endif
