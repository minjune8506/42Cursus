#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*tail;
	int		size;
}t_stack;

typedef struct s_cmd
{
	int	count_ra;
	int	count_rb;
	int	count_pa;
	int	count_pb;
	int	count_origin;
	int	pivot_b;
	int	pivot_s;
}t_cmd;

void		print_all(t_stack **stack_a, t_stack **stack_b);
/*
**stack_init.c
*/
t_stack		*init_stack(void);
t_cmd		*init_cmd(int count);
t_node		*init_node(int data);
/*
**stack_utils.c
*/
void		push(t_stack *stack, int data);
void		push_back(t_stack *stack, int data);
t_node		*pop(t_stack *stack);
t_node		*pop_back(t_stack *stack);
void		destroy_stack(t_stack *stack);
/*
**sort_utils.c
*/
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
/*
**sort_utils2.c
*/
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
/*
**sort_utils3.c
*/
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
/*
**check.c
*/
void		check_valid(char **av);
void		check_range(char **av);
void		check_overlap(int *arr, int size);
/*
**parse.c
*/
void		parse(char **av, t_stack **stack);
/*
**utils.c
*/
void		print_error(void);
void		split_free(char **str);
long long	ft_atoi_long(const char *str);
/*
small_sort.c
*/
int			get_max(t_stack **stack, int size);
int			get_min(t_stack **stack, int size);
void		three_count_sort(t_stack **stack);
void		three_sort(t_stack **stack);
/*
small_count_sort.c
*/
int			is_sorted(t_stack **stack, int count);
int			is_b_sorted(t_stack **stack_a, t_stack **stack_b, int count);
void		five_count_sort(t_stack **stack_a, t_stack **stack_b);
/*
get_pivot.c
*/
void		insertion_sort(int *list, int n);
int			get_mid(t_stack **stack, int size);
/*
sort_a.c
*/
void		rotate_back(t_stack **stack_a, t_stack **stack_b, t_cmd *cmd);
void		a_to_b(t_stack **stack_a, t_stack **stack_b, int count);
/*
sort_b.c
*/
void		two_sort_b(t_stack **stack_a, t_stack **stack_b);
void		b_to_a(t_stack **stack_a, t_stack **stack_b, int count);

#endif