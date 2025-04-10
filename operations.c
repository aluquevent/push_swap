#include "push_swap.h"

void	swap(t_ring *ring)
{
	t_node	*top_node;
	t_node	*second_node;
	t_node	*last_node;
	t_node	*third_node;

	if (!ring || ring->size < 2)
		return ;
	top_node = ring->head;
	second_node = top_node->next;
	last_node = top_node->prev;
	third_node = second_node->next;
	second_node->prev = last_node;
	last_node->next = second_node;
	top_node->next = third_node;
	third_node->prev = top_node;
	top_node->prev = second_node;
	second_node->next = top_node;
	ring->head = second_node;
}

void	ss(t_ring *a, t_ring *b)
{
	swap(a);
	swap(b);
}

void	push(t_ring *origin, t_ring *dest)
{
	t_node	*node_to_push;

	if (!origin || origin->size == 0)
		return ;
	node_to_push = origin->head;
	extract_node(origin, node_to_push);
	add_front(dest, node_to_push);
}

void	rotate(t_ring *ring)
{
	if (!ring || ring->size < 2)
		return ;
	ring->head = ring->head->next;	
}

void	rr(t_ring *a, t_ring * b)
{
	rotate(a);
	rotate(b);
}

void	r_rotate(t_ring *ring)
{
	if (!ring || ring->size < 2)
		return ;
	ring->head = ring->head->prev;	
}

void	rrr(t_ring *a, t_ring *b)
{
	r_rotate(a);
	r_rotate(b);
}
