#include "push_swap.h"
#include <stdlib.h>

int
	small_sort_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 2)
	{
		if (!is_sorted(stack_a, count))
			sa(stack_a);
		return (1);
	}
	else if (count == 3)
	{
		three_sort(stack_a);
		return (1);
	}
	else if (count == 5)
	{
		five_count_sort(stack_a, stack_b);
		return (1);
	}
	return (0);
}

t_cmd
	*init_cmd(int count)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		print_error();
	cmd->count_pa = 0;
	cmd->count_pb = 0;
	cmd->count_ra = 0;
	cmd->count_rb = 0;
	cmd->pivot_b = 0;
	cmd->pivot_s = 0;
	cmd->count_origin = count;
	return (cmd);
}

void	sort_a(t_stack **stack_a, t_stack **stack_b, t_cmd **cmd, int count)
{
	int	i;

	i = -1;
	(*cmd)->pivot_b = ((get_min(stack_a, count) + get_max(stack_a, count)) / 2);
	(*cmd)->pivot_s = ((get_min(stack_a, count) + (*cmd)->pivot_b) / 2);
	while (++i < count)
	{
		if ((*stack_a)->top->data > (*cmd)->pivot_b)
		{
			ra(stack_a);
			(*cmd)->count_ra++;
		}
		else
		{
			pb(stack_a, stack_b);
			(*cmd)->count_pb++;
			if ((*stack_b)->top->data > (*cmd)->pivot_s)
			{
				rb(stack_b);
				(*cmd)->count_rb++;
			}
		}
	}
}

void	rotate_back(t_stack **stack_a, t_stack **stack_b, t_cmd *cmd)
{
	int	i;

	i = -1;
	if (cmd->count_ra > cmd->count_rb)
	{
		while (++i < cmd->count_rb)
			rrr(stack_a, stack_b);
		while (i++ < cmd->count_ra && cmd->count_origin < (*stack_a)->size)
			rra(stack_a);
	}
	else
	{
		while (++i < cmd->count_ra)
			rrr(stack_a, stack_b);
		while (i++ < cmd->count_rb && cmd->count_origin < (*stack_b)->size)
			rrb(stack_b);
	}
}

void	a_to_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_cmd	*cmd;

	if (is_sorted(stack_a, count))
		return ;
	if (small_sort_a(stack_a, stack_b, count))
		return ;
	cmd = init_cmd(count);
	sort_a(stack_a, stack_b, &cmd, count);
	rotate_back(stack_a, stack_b, cmd);
	a_to_b(stack_a, stack_b, cmd->count_ra);
	b_to_a(stack_a, stack_b, cmd->count_rb);
	b_to_a(stack_a, stack_b, cmd->count_pb - cmd->count_rb);
	free(cmd);
}

void	two_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->top->data < (*stack_b)->top->next->data)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	small_sort_b(t_stack **stack_a, t_stack **stack_b, int count)
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

void	sort_b(t_stack **stack_a, t_stack **stack_b, t_cmd **cmd, int count)
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
