#include "operations.h"

static void	sort_two(t_ring *a, t_ops *ops)
{
	if (a->head->value > a->head->next->value)
		do_sa(a, ops);
}

static void	sort_three(t_ring *a, t_ops *ops)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first > second && second < third && first < third)
		do_sa(a, ops);
	else if (first > second && second > third)
	{
		do_sa(a, ops);
		do_rra(a, ops);
	}
	else if (first > second && second < third && first > third)
		do_ra(a, ops);
	else if (first < second && second > third && first < third)
	{
		do_sa(a, ops);
		do_ra(a, ops);
	}
	else if (first < second && second > third && first > third)
		do_rra(a, ops);
}

// Esta función determina si un número es de la mitad superior o inferior del rango
static int is_in_upper_half(t_ring *a, int value)
{
	t_node *min_node = get_min(a);
	t_node *max_node = get_max(a);
	int min_val = min_node->value;
	int max_val = max_node->value;
	int median = min_val + (max_val - min_val) / 2;
	
	return (value > median);
}

// Push inicial optimizado - envía números a B parcialmente ordenados
static void optimized_push_initial(t_ring *a, t_ring *b, t_ops *ops)
{
	int elements_to_push;
	int median_value;
	int chunks = 2;  // Dividimos en 2 chunks para empezar (puede ser ajustado)
	int i;
	int pushed;
	int size;
	t_node *current;
	
	// Si hay pocos elementos, los manejamos directamente
	if (a->size <= 5)
	{
		while (a->size > 3)
			do_pb(a, b, ops);
		return;
	}
	
	size = a->size;
	elements_to_push = size - 3;
	
	// Fase 1: Empujar aproximadamente la mitad de los números más pequeños
	pushed = 0;
	while (pushed < elements_to_push / 2)
	{
		if (!is_in_upper_half(a, a->head->value))
		{
			do_pb(a, b, ops);
			pushed++;
		}
		else
			do_ra(a, ops);
		
		// Si dimos toda la vuelta, tomamos lo que podamos
		if (pushed == 0 && a->head == a->head->next->next->next)
		{
			do_pb(a, b, ops);
			pushed++;
		}
	}
	
	// Fase 2: Empujar el resto manteniendo los 3 mejores elementos en A
	while (a->size > 3)
	{
		// Seleccionar el elemento más adecuado para empujar
		int best_pos = 0;
		int min_cost = INT_MAX;
		
		// Buscar el elemento que causará menos operaciones al volver a insertarlo después
		for (i = 0; i < a->size; i++)
		{
			int potential_cost;
			current = a->head;
			for (int j = 0; j < i; j++)
				current = current->next;
				
			// Calcula un costo aproximado
			potential_cost = (i <= a->size / 2) ? i : a->size - i;
			
			if (potential_cost < min_cost)
			{
				min_cost = potential_cost;
				best_pos = i;
			}
		}
		
		// Rotamos hasta el mejor elemento para hacer push
		if (best_pos <= a->size / 2)
		{
			for (i = 0; i < best_pos; i++)
				do_ra(a, ops);
		}
		else
		{
			for (i = 0; i < a->size - best_pos; i++)
				do_rra(a, ops);
		}
		
		do_pb(a, b, ops);
	}
}

// Optimizar el ordenamiento para casos especiales
static void optimize_small_sort(t_ring *a, t_ring *b, t_ops *ops)
{
	// Caso de 4 elementos
	if (a->size == 4)
	{
		// Buscar la posición del elemento más pequeño
		t_node *min_node = get_min(a);
		int min_pos = get_position(a, min_node);
		
		// Rotar hasta que el mínimo esté arriba
		if (min_pos <= a->size / 2)
		{
			while (min_pos > 0)
			{
				do_ra(a, ops);
				min_pos--;
			}
		}
		else
		{
			while (min_pos < a->size)
			{
				do_rra(a, ops);
				min_pos++;
			}
		}
		
		// Push el mínimo a B, ordenar los 3 restantes, y devolver el mínimo a A
		do_pb(a, b, ops);
		sort_three(a, ops);
		do_pa(b, a, ops);
		return;
	}
	
	// Caso de 5 elementos
	if (a->size == 5)
	{
		// Buscar la posición del elemento más pequeño
		t_node *min_node = get_min(a);
		int min_pos = get_position(a, min_node);
		
		// Rotar hasta que el mínimo esté arriba
		if (min_pos <= a->size / 2)
		{
			while (min_pos > 0)
			{
				do_ra(a, ops);
				min_pos--;
			}
		}
		else
		{
			while (min_pos < a->size)
			{
				do_rra(a, ops);
				min_pos++;
			}
		}
		
		// Push el mínimo a B
		do_pb(a, b, ops);
		
		// Buscar el segundo elemento más pequeño
		min_node = get_min(a);
		min_pos = get_position(a, min_node);
		
		// Rotar hasta que el segundo mínimo esté arriba
		if (min_pos <= a->size / 2)
		{
			while (min_pos > 0)
			{
				do_ra(a, ops);
				min_pos--;
			}
		}
		else
		{
			while (min_pos < a->size)
			{
				do_rra(a, ops);
				min_pos++;
			}
		}
		
		// Push el segundo mínimo a B
		do_pb(a, b, ops);
		
		// Ordenar los 3 restantes y devolver los dos mínimos a A
		sort_three(a, ops);
		do_pa(b, a, ops);
		do_pa(b, a, ops);
		return;
	}
}

int	find_target_position(t_ring *a, int value)
{
	t_node	*current;
	t_node	*min_node;
	int		target_pos;
	int		i;
	int		closest_larger_value;
	int		closest_larger_pos;

	if (!a || a->size == 0)
		return (0);
	
	// Find the smallest number in stack A that is larger than value
	current = a->head;
	closest_larger_value = INT_MAX;
	closest_larger_pos = -1;
	i = 0;
	
	while (i < a->size)
	{
		if (current->value > value && current->value < closest_larger_value)
		{
			closest_larger_value = current->value;
			closest_larger_pos = i;
		}
		current = current->next;
		i++;
	}
	
	// If we found a position, return it
	if (closest_larger_pos != -1)
		return (closest_larger_pos);
	
	// If we didn't find a larger value, we need to place it after the largest value
	// which means placing it before the smallest value
	min_node = get_min(a);
	return (get_position(a, min_node));
}

t_cost	calculate_cost(t_ring *a, t_ring *b, int pos_b)
{
	t_cost	cost;
	t_node	*current;
	int		target_pos;
	int		i;

	cost.ra = 0;
	cost.rb = 0;
	cost.rr = 0;
	cost.rra = 0;
	cost.rrb = 0;
	cost.rrr = 0;
	cost.total = 0;
	cost.value = 0;
	
	current = b->head;
	i = 0;
	while (i < pos_b)
	{
		current = current->next;
		i++;
	}
	
	target_pos = find_target_position(a, current->value);
	cost.value = current->value;

	// Calculate rotations needed for stack A
	if (target_pos <= a->size / 2)
		cost.ra = target_pos;
	else
		cost.rra = a->size - target_pos;
	
	// Calculate rotations needed for stack B
	if (pos_b <= b->size / 2)
		cost.rb = pos_b;
	else
		cost.rrb = b->size - pos_b;
	
	// Calculate combined rotations (when we can rotate both stacks simultaneously)
	cost.rr = (cost.ra < cost.rb) ? cost.ra : cost.rb;
	cost.rrr = (cost.rra < cost.rrb) ? cost.rra : cost.rrb;
	
	// Optimize by using combined rotations
	if (cost.rr > 0)
	{
		cost.ra -= cost.rr;
		cost.rb -= cost.rr;
	}
	
	if (cost.rrr > 0)
	{
		cost.rra -= cost.rrr;
		cost.rrb -= cost.rrr;
	}
	
	// Calculate total cost
	cost.total = cost.ra + cost.rb + cost.rra + cost.rrb + cost.rr + cost.rrr + 1; // +1 for the push operation
	
	return (cost);
}

t_cost	find_best_move(t_ring *a, t_ring *b)
{
	t_cost	min_cost;
	t_cost	current_cost;
	int		i;

	min_cost.total = INT_MAX;
	min_cost.ra = 0;
	min_cost.rb = 0;
	min_cost.rr = 0;
	min_cost.rra = 0;
	min_cost.rrb = 0;
	min_cost.rrr = 0;
	min_cost.value = 0;
	
	i = 0;
	while (i < b->size)
	{
		current_cost = calculate_cost(a, b, i);
		if (current_cost.total < min_cost.total)
			min_cost = current_cost;
		i++;
	}
	
	return (min_cost);
}

void	execute_moves(t_ring *a, t_ring *b, t_cost cost, t_ops *ops)
{
	// Execute combined rotations first
	while (cost.rr > 0)
	{
		do_rr(a, b, ops);
		cost.rr--;
	}
	
	while (cost.rrr > 0)
	{
		do_rrr(a, b, ops);
		cost.rrr--;
	}
	
	// Then execute individual rotations
	while (cost.ra > 0)
	{
		do_ra(a, ops);
		cost.ra--;
	}
	
	while (cost.rb > 0)
	{
		do_rb(b, ops);
		cost.rb--;
	}
	
	while (cost.rra > 0)
	{
		do_rra(a, ops);
		cost.rra--;
	}
	
	while (cost.rrb > 0)
	{
		do_rrb(b, ops);
		cost.rrb--;
	}
	
	// Finally, push from B to A
	do_pa(b, a, ops);
}

void	final_rotation(t_ring *a, t_ops *ops)
{
	t_node	*min_node;
	int		min_pos;

	min_node = get_min(a);
	min_pos = get_position(a, min_node);
	
	if (min_pos <= a->size / 2)
	{
		while (min_pos > 0)
		{
			do_ra(a, ops);
			min_pos--;
		}
	}
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos > 0)
		{
			do_rra(a, ops);
			min_pos--;
		}
	}
}

void	turkish_sort(t_ring *a, t_ring *b, t_ops *ops)
{
	t_cost	best_move;
	int		original_size;
	
	original_size = a->size;
	
	// Handle special cases for small sizes
	if (original_size <= 5)
	{
		optimize_small_sort(a, b, ops);
		return;
	}
	
	// Push elements to B in an optimized way
	optimized_push_initial(a, b, ops);
	
	// Sort the remaining 3 elements in stack A
	if (a->size == 3)
		sort_three(a, ops);
	else if (a->size == 2)
		sort_two(a, ops);
	
	// Push back elements from B to A in optimal order
	while (b->size > 0)
	{
		best_move = find_best_move(a, b);
		execute_moves(a, b, best_move, ops);
	}
	
	// Rotate A to get the smallest element at the top
	final_rotation(a, ops);
}

void	sort_stack(t_ring *a, t_ring *b)
{
	t_ops	ops;

	if (!a || !b)
		return ;
	
	ops = init_ops_counter();
	
	if (is_sorted(a) || a->size <= 1)
		return ;
	else if (a->size == 2)
		sort_two(a, &ops);
	else if (a->size == 3)
		sort_three(a, &ops);
	else
		turkish_sort(a, b, &ops);
	
	print_ops_summary(&ops);
}