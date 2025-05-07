#include "../includes/push_swap.h"

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

t_ring	*init_ring_a(int *nums, size_t elements)
{
	t_ring	*a;
	t_node	*new_node;
	size_t	i;

	a = init_ring();
	if (!a)
		return (NULL);
	i = 0;
	while (i < elements)
	{
		new_node = create_node(nums[i]);
		if (!new_node)
		{
			free_ring(a);
			return (NULL);
		}
		add_back(a, new_node);
		i++;
	}
	return (a);
}

void	init_cost(t_cost *cost)
{
	cost->ra = 0;
	cost->rb = 0;
	cost->rr = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rrr = 0;
	cost->total = 0;
	cost->value = 0;
}

void	init_ops_counter(void)
{
	g_ops.sa = 0;
	g_ops.sb = 0;
	g_ops.ss = 0;
	g_ops.pa = 0;
	g_ops.pb = 0;
	g_ops.ra = 0;
	g_ops.rb = 0;
	g_ops.rr = 0;
	g_ops.rra = 0;
	g_ops.rrb = 0;
	g_ops.rrr = 0;
	g_ops.total = 0;
}

int	init_stacks(t_ring **stack_a, t_ring **stack_b, int *nums, size_t elements)
{
	*stack_a = init_ring_a(nums, elements);
	*stack_b = init_ring();
	if (!*stack_a || !*stack_b)
	{
		if (*stack_a)
			free_ring(*stack_a);
		if (*stack_b)
			free_ring(*stack_b);
		ft_printf("Error: Memory allocation failed\n");
		return (0);
	}
	return (1);
}

