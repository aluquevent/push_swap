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

// t_node	*find_node(t_ring *ring, int value)
// {
//
// }


