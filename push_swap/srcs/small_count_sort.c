#include "push_swap.h"

int
	is_sorted(t_stack **stack, int count)
{
	t_node	*temp;

	if (count == 0 || count == 1)
		return (1);
	temp = (*stack)->top;
	while (--count > 0)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int
	is_b_sorted(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_node	*node;
	int		i;

	i = count;
	node = (*stack_a)->top;
	while (--count > 0)
	{
		if (node->data > node->next->data)
			node = node->next;
		else
			return (0);
	}
	while (i-- > 0)
		pa(stack_a, stack_b);
	return (1);
}

void	five_count_sort(t_stack **stack_a, t_stack **stack_b)
{
	int			pivot;
	int			pb_count;
	int			ra_count;

	pivot = get_mid(stack_a, 5);
	pb_count = 0;
	ra_count = 0;
	while (1)
	{
		if ((*stack_a)->top->data < pivot)
		{
			pb(stack_a, stack_b);
			pb_count++;
		}
		else
		{
			ra(stack_a);
			ra_count++;
		}
		if (pb_count == 2)
			break ;
	}
	while (ra_count-- && (*stack_a)->size != 3)
		rra(stack_a);
	three_sort(stack_a);
	two_sort_b(stack_a, stack_b);
}
