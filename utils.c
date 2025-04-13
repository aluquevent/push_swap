#include "push_swap.h"

void	free_ring(t_ring *ring)
{
	t_node	*current;
	t_node	*next;

	if (!ring)
		return ;
	if (ring->size > 0 && ring->head)
	{
		current = ring->head;
		while (ring->size--)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	free(ring);
}

t_node	*find_node(t_ring *ring, int value)
{
	t_node	*current;
	size_t	pos;

	if (!ring || ring->size == 0)
		return (NULL);
	current = ring->head;
	pos = 0;
	while (pos < ring->size)
	{
		if (current->value == value)
			return (current);
		current = current->next;
		pos++;
	}
	return (NULL);
}

int	count_moves(t_ring *ring, t_node *node, int target_pos)
{
	int	current_pos;
	int	forward_moves;
	int	backward_moves;

	if (!ring || !node || ring->size < 2)
		return (0);
	current_pos = get_position(ring, node);
	if (current_pos == -1)
		return (-1);
	forward_moves = (target_pos - current_pos + ring->size) % ring->size;
	backward_moves = (current_pos - target_pos + ring->size) % ring->size;
	if (forward_moves < backward_moves)
		return (forward_moves);
	else
		return (-backward_moves);
}

