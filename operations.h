#include "push_swap.h"

typedef struct s_ops
{
	int	sa_count;
	int	sb_count;
	int	ss_count;
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
	int	rr_count;
	int	rra_count;
	int	rrb_count;
	int	rrr_count;
	int	total;
}	t_ops;

t_ops	init_ops_counter(void);
void	do_sa(t_ring *a, t_ops *ops);
void	do_sb(t_ring *b, t_ops *ops);
void	do_ss(t_ring *a, t_ring *b, t_ops *ops);
void	do_pa(t_ring *b, t_ring *a, t_ops *ops);
void	do_pb(t_ring *a, t_ring *b, t_ops *ops);
void	do_ra(t_ring *a, t_ops *ops);
void	do_rb(t_ring *b, t_ops *ops);
void	do_rr(t_ring *a, t_ring *b, t_ops *ops);
void	do_rra(t_ring *a, t_ops *ops);
void	do_rrb(t_ring *b, t_ops *ops);
void	do_rrr(t_ring *a, t_ring *b, t_ops *ops);
void	print_ops_summary(t_ops *ops);

