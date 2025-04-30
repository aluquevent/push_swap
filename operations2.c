#include "operations.h"

t_ops	init_ops_counter(void)
{
	t_ops	counter;

	counter.sa_count = 0;
	counter.sb_count = 0;
	counter.ss_count = 0;
	counter.pa_count = 0;
	counter.pb_count = 0;
	counter.ra_count = 0;
	counter.rb_count = 0;
	counter.rr_count = 0;
	counter.rra_count = 0;
	counter.rrb_count = 0;
	counter.rrr_count = 0;
	counter.total = 0;
	return (counter);
}

void	do_sa(t_ring *a, t_ops *ops)
{
	swap(a);
	ft_printf("sa\n");
	ops->sa_count++;
	ops->total++;
}

void	do_sb(t_ring *b, t_ops *ops)
{
	swap(b);
	ft_printf("sb\n");
	ops->sb_count++;
	ops->total++;
}

void	do_ss(t_ring *a, t_ring *b, t_ops *ops)
{
	ss(a, b);
	ft_printf("ss\n");
	ops->ss_count++;
	ops->total++;
}

void	do_pa(t_ring *b, t_ring *a, t_ops *ops)
{
	push(b, a);
	ft_printf("pa\n");
	ops->pa_count++;
	ops->total++;
}

void	do_pb(t_ring *a, t_ring *b, t_ops *ops)
{
	push(a, b);
	ft_printf("pb\n");
	ops->pb_count++;
	ops->total++;
}

void	do_ra(t_ring *a, t_ops *ops)
{
	rotate(a, false);
	ft_printf("ra\n");
	ops->ra_count++;
	ops->total++;
}

void	do_rb(t_ring *b, t_ops *ops)
{
	rotate(b, false);
	ft_printf("rb\n");
	ops->rb_count++;
	ops->total++;
}

void	do_rr(t_ring *a, t_ring *b, t_ops *ops)
{
	rr(a, b, false);
	ft_printf("rr\n");
	ops->rr_count++;
	ops->total++;
}

void	do_rra(t_ring *a, t_ops *ops)
{
	rotate(a, true);
	ft_printf("rra\n");
	ops->rra_count++;
	ops->total++;
}

void	do_rrb(t_ring *b, t_ops *ops)
{
	rotate(b, true);
	ft_printf("rrb\n");
	ops->rrb_count++;
	ops->total++;
}

void	do_rrr(t_ring *a, t_ring *b, t_ops *ops)
{
	rr(a, b, true);
	ft_printf("rrr\n");
	ops->rrr_count++;
	ops->total++;
}

void	print_ops_summary(t_ops *ops)
{
	ft_printf("\n=== OPERATIONS SUMMARY ===\n");
	ft_printf("sa: %d\n", ops->sa_count);
	ft_printf("sb: %d\n", ops->sb_count);
	ft_printf("ss: %d\n", ops->ss_count);
	ft_printf("pa: %d\n", ops->pa_count);
	ft_printf("pb: %d\n", ops->pb_count);
	ft_printf("ra: %d\n", ops->ra_count);
	ft_printf("rb: %d\n", ops->rb_count);
	ft_printf("rr: %d\n", ops->rr_count);
	ft_printf("rra: %d\n", ops->rra_count);
	ft_printf("rrb: %d\n", ops->rrb_count);
	ft_printf("rrr: %d\n", ops->rrr_count);
	ft_printf("Total operations: %d\n", ops->total);
}
