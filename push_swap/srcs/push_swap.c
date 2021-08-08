/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:44:44 by minjkim2          #+#    #+#             */
/*   Updated: 2021/08/07 23:44:44 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack();
	stack_b = init_stack();
	parse(av, &stack_a);
	if ((ac == 1) | is_sorted(&stack_a, stack_a->size))
	{
		destroy_stack(stack_a);
		destroy_stack(stack_b);
		return (0);
	}
	a_to_b(&stack_a, &stack_b, stack_a->size);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
}
