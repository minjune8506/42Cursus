#include "push_swap.h"
#include <stdlib.h>

void
	two_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->top->data < (*stack_b)->top->next->data)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

static int
	small_sort_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 0)
		return (1);
	if (count == 1)
	{
		pa(stack_a, stack_b);
		return (1);
	}
	else if (count == 2)
	{
		two_sort_b(stack_a, stack_b);
		return (1);
	}
	if (is_b_sorted(stack_a, stack_b, count))
		return (1);
	return (0);
}

static void
	sort_b(t_stack **stack_a, t_stack **stack_b, t_cmd **cmd, int count)
{
	int	i;

	i = -1;
	(*cmd)->pivot_b = ((get_min(stack_b, count) + get_max(stack_b, count)) / 2);
	(*cmd)->pivot_s = ((get_min(stack_b, count) + (*cmd)->pivot_b) / 2);
	while (++i < count)
	{
		if ((*stack_b)->top->data <= (*cmd)->pivot_s)
		{
			rb(stack_b);
			(*cmd)->count_rb++;
		}
		else
		{
			pa(stack_a, stack_b);
			(*cmd)->count_pa++;
			if ((*stack_a)->top->data <= (*cmd)->pivot_b)
			{
				ra(stack_a);
				(*cmd)->count_ra++;
			}
		}
	}
}

void
	b_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_cmd	*cmd;

	if (small_sort_b(stack_a, stack_b, count))
		return ;
	cmd = init_cmd(count);
	sort_b(stack_a, stack_b, &cmd, count);
	a_to_b(stack_a, stack_b, cmd->count_pa - cmd->count_ra);
	rotate_back(stack_a, stack_b, cmd);
	a_to_b(stack_a, stack_b, cmd->count_ra);
	b_to_a(stack_a, stack_b, cmd->count_rb);
	free(cmd);
}
