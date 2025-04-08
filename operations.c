#include "push_swap.h"

void	sa(t_ring *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->head;
	second = a->head->next;
	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	a->head = second;
}

void	sb(t_ring *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->head;
	second = b->head->next;
	second->prev = first->prev;
	first->prev = second;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	b->head = second;
}

void	ss(t_ring *a, t_ring *b)
{
	sa(a);
	sb(b);
}

void	pa(t_ring *a, t_ring *b)
{
	t_node	*node_to_push;

	if (!b || b->size == 0)
		return ;
	node_to_push = b->head;
	extract_node(b, node_to_push);
	add_front(a, node_to_push);
}

void	pb(t_ring *a, t_ring *b)
{
	t_node	*node_to_push;

	if (!a || a->size == 0)
		return ;
	node_to_push = a->head;
	extract_node(a, node_to_push);
	add_front(b, node_to_push);

}

void	ra(t_ring *a)
{
	if (!a || a->size < 2)
		return ;
	a->head = a->head->next;	
}

void	rb(t_ring *b)
{
	if (!b || b->size < 2)
		return ;
	b->head = b->head->next;	
}

void	rr(t_ring *a, t_ring * b)
{
	ra(a);
	rb(b);
}

void	rra(t_ring *a)
{
	if (!a || a->size < 2)
		return ;
	a->head = a->head->prev;	
}

void	rrb(t_ring *b)
{
	if (!b || b->size < 2)
		return ;
	b->head = b->head->prev;	
}

void	rrr(t_ring *a, t_ring *b)
{
	rra(a);
	rrb(b);
}
