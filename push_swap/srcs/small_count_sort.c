/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_count_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:44:48 by minjkim2          #+#    #+#             */
/*   Updated: 2021/08/07 23:44:48 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
	t_cmd		*cmd;
	int			pivot;

	cmd = init_cmd(5);
	pivot = get_mid(stack_a, 5);
	while (1)
	{
		if ((*stack_a)->top->data < pivot)
		{
			pb(stack_a, stack_b);
			cmd->count_pb++;
		}
		else
		{
			ra(stack_a);
			cmd->count_ra++;
		}
		if (cmd->count_pb == 2)
			break ;
	}
	while (cmd->count_ra-- && (*stack_a)->size != 3)
		rra(stack_a);
	three_sort(stack_a);
	two_sort_b(stack_a, stack_b);
	free(cmd);
}
