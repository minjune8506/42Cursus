#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>

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
	int count_ra;
	int count_rb;
	int count_pa;
	int count_pb;
	int count_origin;
	int pivot_b;
	int pivot_s;
}t_cmd;
void	print_all(t_stack **stack_a, t_stack **stack_b);

/*
**stack_init.c
*/
t_stack *init_stack();
t_node *init_node(int data);
/*
**stack_utils.c
*/
void	push(t_stack *stack, int data);
void	push_back(t_stack *stack, int data);
t_node *pop(t_stack *stack);
t_node 	*pop_back(t_stack *stack);
void	destroy_stack(t_stack *stack);
/*
**sort_utils.c
*/
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
/*
**sort_utils2.c
*/
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
/*
**sort_utils3.c
*/
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
/*
**check.c
*/
void check_valid(char **av);
void check_range(char **av);
void check_overlap(int *arr, int size);
/*
**parse.c
*/
void	parse(char **av, t_stack **stack);
/*
**utils.c
*/
void	print_error();
void	split_free(char **str);
long long	ft_atoi_long(const char *str);
/*
mid.c
*/
int		get_mid(t_stack **stack, int size);

/*
small_sort.c
*/
int	get_max(t_stack **stack, int size);
int	get_min(t_stack **stack, int size);
void	three_count_sort(t_stack **stack);
void	three_sort(t_stack **stack);
void	five_sort(t_stack **stack_a, t_stack **stack_b);
/*
small_count_sort.c
*/
int	is_sorted(t_stack **stack, int count);
int	is_b_sorted(t_stack **stack_a, t_stack **stack_b, int count);
void	five_count_sort(t_stack **stack_a, t_stack **stack_b);
/*
get_pivot.c
*/
void	insertion_sort(int *list, int n);
void	get_pivot(t_stack **stack, int *pivot_b, int *pivot_s, int size);
/*
notyet
*/
void	a_to_b(t_stack **stack_a, t_stack **stack_b, int count);
void	b_to_a(t_stack **stack_a, t_stack **stack_b, int count);
void	two_sort_b(t_stack **stack_a, t_stack **stack_b);
#endif