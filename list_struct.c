#include "push_swap.h"

t_ring	*init_ring(void)
{
		t_ring	*ring;
		
		ring = (t_ring *)malloc(sizeof(t_ring));
		if (!ring)
			return (NULL);
		ring->head = NULL;
		ring->size = 0;
		return (ring);
}

t_node	*create_node(int value)
{
	t_node	*new;
	
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = new;
	new->next = new;
	return (new);
}

void	add_back(t_ring *ring, t_node *node)
{
	t_node	*last_node;

	if (!ring || !node)
		return ;
	if (ring->size == 0)
		ring->head = node;
	else if (ring->size == 1)
	{
		node->next = ring->head;
		node->prev = ring->head;
		ring->head->next = node;
		ring->head->prev = node;
	}
	else
	{
		last_node = ring->head->prev;
		last_node->next = node;
		node->prev = last_node;
		node->next = ring->head;
		ring->head->prev = node;
	}
	ring->size++;
}

void	add_front(t_ring *ring, t_node *node)
{
	t_node	*last_node;

	if(!ring || !node)
		return ;
	if (ring->size == 0)
	{
		ring->head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		last_node = ring->head->prev;
		node->next = ring->head;
		node->prev = last_node;
		last_node->next = node;
		ring->head->prev = node;
		ring->head = node;
	}
	ring->size++;
}

void	extract_node(t_ring *ring, t_node *node)
{
	if (!ring || !node || ring->size == 0)
		return ;
	if (ring->size == 1)
	{
		ring->head = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (ring->head == node)
			ring->head = node->next;
	}
	ring->size--;
}

int	get_position(t_ring *ring, t_node *node)
{
	t_node	*current;
	size_t	pos;

	if (!ring || !node || ring->size == 0)
		return (-1);
	current = ring->head;
	pos = 0;
//good?	
	while (pos < ring->size)
	{
		if (current == node)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

t_node	*get_max(t_ring *ring)
{
	t_node	*max;
	t_node	*current;
	int		pos;

	if (!ring || ring->size == 0)
		return (NULL);
	max = ring->head;
	current = ring->head;
	pos = 0;
	while (pos < ring->size)
	{
		if (max->value < current->value)
			max = current;
		current = current->next;
		pos++;
	}
	return (max);
}

t_node	*get_min(t_ring *ring)
{
	t_node	*min;
	t_node	*current;
	int		pos;

	if (!ring || ring->size == 0)
		return (NULL);
	min = ring->head;
	current = ring->head;
	pos = 0;
	while (pos < ring->size)
	{
		if (min->value > current->value)
			min = current;
		current = current->next;
		pos++;
	}
	return (min);
}

int	is_sorted(t_ring *ring)
{
	int		pos;
	t_node	*current;
	
	if (!ring || ring->size < 2)
		return (0);
	pos = 0;
	current = ring->head;
	while (pos < ring->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		pos++;
	}
	return (1);
}
/*
 * CIRCULAR MANAGEMENT
y	t_node	create_node(int value);
y	void	add_back(t_ring *ring, t_node *node);
y	void	add_front(t_ring *ring, t_node *node);
y	void	delete_node(t_ring *ring, t_node *node);
	void	free_ring(t_ring *ring);
y	t_ring	*init_ring(void);
	t_node	*find_node(t_ring *ring, int value);

	OPERATIONS
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

	UTILS
y	t_node	*get_max(t_ring *ring);
y	t_node	*get_min(t_ring *ring);
y	int		is_sorted(t_ring *ring);
y	int		get_position(t_ring *ring, t_node *node);
	int		count_moves(t_ring *ring, t_node *node, int target_pos);
	
	DEBUGGING
	void	print_ring(t_ring *ring);
*/
