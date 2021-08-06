#include "push_swap.h"

#include <stdlib.h>

int
	get_max(t_stack **stack, int size)
{
	t_node	*temp;
	int		max;

	temp = (*stack)->top;
	max = temp->data;
	while (--size > 0)
	{
		if (max < temp->next->data)
			max = temp->next->data;
		temp = temp->next;
	}
	return (max);
}

int
	get_min(t_stack **stack, int size)
{
	t_node	*temp;
	int		min;

	temp = (*stack)->top;
	min = temp->data;
	while (--size > 0)
	{
		if (min > temp->next->data)
			min = temp->next->data;
		temp = temp->next;
	}
	return (min);
}

void
	three_count_sort(t_stack **stack)
{
	if ((*stack)->top->data < (*stack)->top->next->data)
	{
		if ((*stack)->top->next->data < (*stack)->top->next->next->data)
			return ;
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if ((*stack)->top->data > (*stack)->top->next->next->data)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	if ((*stack)->top->data > (*stack)->top->next->data)
		sa(stack);
}

void
	three_sort(t_stack **stack)
{
	if ((*stack)->size == 3)
	{
		if (!is_sorted(stack, (*stack)->size))
		{
			if ((*stack)->top->next->data > (*stack)->top->data && \
				(*stack)->top->next->data > (*stack)->tail->data)
				rra(stack);
			else if ((*stack)->top->data > (*stack)->top->next->data && \
					(*stack)->top->data > (*stack)->tail->data)
				ra(stack);
			if ((*stack)->top->data > (*stack)->top->next->data)
				sa(stack);
		}
	}
	else
		three_count_sort(stack);
}

void
	five_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;

	max = get_max(stack_a, (*stack_a)->size);
	min = get_min(stack_a, (*stack_a)->size);
	while ((*stack_a)->size != 3)
	{
		if ((*stack_a)->top->data == max || \
		(*stack_a)->top->data == min)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	three_sort(stack_a);
	if (!is_sorted(stack_b, (*stack_b)->size))
	{
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
	}
	else
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
