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
	t_node	*max;
	t_node	*min;
	int		max_pos;
	int		min_pos;

	while(a->size > 3)
	{
		max = get_max(a);
		min = get_min(a);
		max_pos = get_position(a, max);
		min_pos = get_position(a, min);
		if (max_pos <= min_pos && (max_pos <= a->size / 2 || (a->size - max_pos) <= a->size / 2))
		{
			if (max_pos <= a->size / 2)
			{
				while (a->head != max)
					do_ra(a, ops);
			}
			else
			{
				while (a->head != max)
					do_rra(a, ops);
			}
		}
		else if (min_pos <= a->size / 2 || (a->size - min_pos) <= a->size / 2)
		{
			if (min_pos <= a->size / 2)
			{
				while (a->head != min)
					do_ra(a, ops);
			}
			else
			{
				while (a->head != min)
					do_rra(a, ops);
			}
			do_pb(a, b, ops);
		}
		else
			do_pb(a, b, ops);
	}
}

int	find_target_position (t_ring *a, int value)
{
	t_node	*current;
	int		min_val = INT_MAX;
	int		max_val = INT_MIN;
	int		min_pos;
	int		max_pos;
	int		i;

	current = a->head;
	i = 0;
	while (i < a->size)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = i;
		}
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = i;
		}
		current = current->next;
		i++;
	}

	if (value < min_val)
		return (min_pos);
	if (value > max_val)
		return ((max_pos + 1) % a->size);
	i = 0;
	current = a->head;
	while (i < a->size)
	{
		if (current->value < value && current->next->value > value)
			return ((i + 1) % a->size);
		current = current->next;
		i++;
	}
	return (0);
}

t_cost	calculate_cost(t_ring *a, t_ring *b, int pos_b)
{
	t_cost	cost;
	t_node	*current;
	int		i;
	int		target_pos;

	current = b->head;
	i = 0;
	while (i < pos_b)
	{
		current = current->next;
		i++;
	}
	target_pos = find_target_position(a, current->value);
	cost.ra = target_pos;
	cost.rb = pos_b;
	cost.rra = a->size - target_pos;
	cost.rrb = b->size - pos_b;
	if (cost.ra < cost.rb)
		cost.rr = cost.ra;
	else
		cost.rr = cost.rb;
	if (cost.rra < cost.rrb)
		cost.rrr = cost.rra;
	else
		cost.rrr = cost.rrb;
	cost.total = cost.ra + cost.rb + cost.rr + cost.rra + cost.rrb + cost.rrr;
	cost.value = current->value;
	return (cost);
}

t_cost	find_best_move(t_ring *a, t_ring *b)
{
	t_cost	min_cost;
	t_cost	current_cost;
	int		i;

	min_cost.total = INT_MAX;
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
	while (cost.rr--)
		do_rr(a, b, ops);
	while (cost.rrr--)
		do_rrr(a, b, ops);
	while (cost.ra--)
		do_ra(a, ops);
	while (cost.rb--)
		do_rb(b, ops);
	while (cost.rra--)
		do_rra(a, ops);
	while (cost.rrb--)
		do_rrb(b, ops);
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
	sort_three(a, ops);
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


