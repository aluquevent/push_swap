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

void print_stack(t_ring *ring, char stack_name)
{
    t_node *current;
    int i;
    
    if (!ring || ring->size == 0)
    {
        ft_printf("Stack %c: [empty]\n", stack_name);
        return;
    }
    
    ft_printf("Stack %c: [", stack_name);
    current = ring->head;
    i = 0;
    while (i < ring->size)
    {
        ft_printf("%d", current->value);
        if (i < ring->size - 1)
            ft_printf(", ");
        current = current->next;
        i++;
    }
    ft_printf("] (size: %d)\n", ring->size);
}

// Función para inicializar el stack A con los argumentos
t_ring *init_ring_a(int argc, char **argv)
{
    t_ring *a;
    t_node *new_node;
    int i;
    
    a = init_ring();
    if (!a)
        return (NULL);
    i = 0;
    while (++i < argc)
    {
        new_node = create_node(ft_atoi(argv[i]));
        if (!new_node)
        {
            free_ring(a);
            return (NULL);
        }
        add_back(a, new_node);
    }
    return (a);
}
