#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void ra(t_stack **stack_a)
{
	t_node *temp;

	if ((*stack_a)->size == 0)
		return ;
	temp = pop(*stack_a);
	push_back(*stack_a, temp->data);
	free(temp);
	ft_putstr_fd("ra\n", 1);
}

void rb(t_stack **stack_b)
{
	t_node *temp;
	
	if ((*stack_b)->size == 0)
	return ;
	temp = pop(*stack_b);
	push_back(*stack_b, temp->data);
	free(temp);
	ft_putstr_fd("rb\n", 1);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putstr_fd("rr\n", 1);
}