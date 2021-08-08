/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:45:29 by minjkim2          #+#    #+#             */
/*   Updated: 2021/08/07 23:45:30 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

void
	rra(t_stack **stack_a)
{
	t_node	*temp;

	if ((*stack_a)->size == 0)
		return ;
	temp = pop_back(*stack_a);
	push(*stack_a, temp->data);
	free(temp);
	ft_putstr_fd("rra\n", 1);
}

void
	rrb(t_stack **stack_b)
{
	t_node	*temp;

	if ((*stack_b)->size == 0)
		return ;
	temp = pop_back(*stack_b);
	push(*stack_b, temp->data);
	free(temp);
	ft_putstr_fd("rrb\n", 1);
}

void
	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*temp;

	if ((*stack_a)->size != 0)
	{
		temp = pop_back(*stack_a);
		push(*stack_a, temp->data);
		free(temp);
	}
	if ((*stack_b)->size != 0)
	{
		temp = pop_back(*stack_b);
		push(*stack_b, temp->data);
		free(temp);
	}
	ft_putstr_fd("rrr\n", 1);
}
