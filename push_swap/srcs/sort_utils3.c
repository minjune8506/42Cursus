#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void rra(t_stack **stack_a)
{
	t_node *temp;

	if ((*stack_a)->size == 0)
		return ;
	temp = pop_back(*stack_a);
	push(*stack_a, temp->data);
	free(temp);
	ft_putstr_fd("rra\n", 1);
}

void rrb(t_stack **stack_b)
{
	t_node *temp;

	if ((*stack_b)->size == 0)
		return ;
	temp = pop_back(*stack_b);
	push(*stack_b, temp->data);
	free(temp);
	ft_putstr_fd("rrb\n", 1);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
