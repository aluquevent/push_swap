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
		do_ra(a , ops);
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

static void	push_initial(t_ring *a, t_ring *b, t_ops *ops)
{
	while (a->size > 3)
		do_pb(a, b, ops);
}

int	find_target_position (t_ring *a, int value)
{
	t_node	*current;
	t_node	*best_node;
	t_node	*max_node;
	int		best_pos;
	int		i;
	int		min_diff;

	if(!a || a->size == 0)
		return (0);
	current = a->head;
	best_node = NULL;
	best_pos = 0;
	i = 0;
	min_diff = INT_MAX;
	while (i < a->size)
	{
		if (current->value > value && current->prev->value < value)
			return (i);
		if (current->value > value && (current->value - value) < min_diff)
		{
			min_diff = current->value - value;
			best_node = current;
			best_pos = i;
		}
		current = current->next;
		i++;
	}
	if (best_node)
		return (best_pos);
	max_node = get_max(a);
	return ((get_position(a, max_node) + 1) % a->size);
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
	if (cost.ra > 0 && cost.rb > 0)
	{
		cost.ra -= cost.rr;
		cost.rb -= cost.rr;
	}
	if (cost.rra > 0 && cost.rrb > 0)
	{
		cost.rra -= cost.rrr;
		cost.rrb -= cost.rrr;
	}
	
	// Calculate total cost
	cost.total = cost.ra + cost.rb + cost.rra + cost.rrb + cost.rr + cost.rrr;
	cost.value = current->value;
	
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
	i = -1;
	while (i++ < b->size)
	{
		current_cost = calculate_cost(a, b, i);
		if (current_cost.total < min_cost.total)
			min_cost = current_cost;
	}
	return (min_cost);
}

void	execute_moves(t_ring *a, t_ring *b, t_cost cost, t_ops *ops)
{
// Execute rotations in optimal order
	
	// First do combined rotations
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
	
	// Then do individual rotations
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
		while (a->head != min_node)
			do_ra(a, ops);
	}
	else
	{
		while (a->head != min_node)
			do_rra(a, ops);
	}
}

void	turkish_sort(t_ring *a, t_ring *b, t_ops *ops)
{
	t_cost	best_move;

	push_initial(a, b, ops);
	if (a->size == 3)
		sort_three(a, ops);
	else if (a->size == 2)
		sort_two(a, ops);
	while (b->size > 0)
	{
		best_move = find_best_move(a, b);
		execute_moves(a, b, best_move, ops);
	}
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


