#include "push_swap.h"

static void	sort_two(t_ring *a)
{
	if (a->head->value > a->head->next->value)
		swap(a);
}

static void	sort_three(t_ring *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first > second && second < third && first < third)
		swap(a);
	else if (first > second && second > third)
	{
		swap(a);
		rotate(a , true);
	}
	else if (first > second && second < third && first > third)
		rotate(a, false);
	else if (first < second && second > third && first < third)
	{
		swap(a);
		rotate(a, false);
	}
	else if (first < second && second > third && first > third)
		rotate(a, true);
}

static void	turkish_sort(t_ring *a, t_ring *b)
{

}
void	sort_stack(t_ring *a, t_ring *b)
{
	if (is_sorted(a) || a->size <= 1)
		return ;
	else if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else
		turkish_sort(a, b);
}


