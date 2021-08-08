/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:42:12 by minjkim2          #+#    #+#             */
/*   Updated: 2021/08/07 23:42:12 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
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

void
	line_length_check(char *line)
{
	if (ft_strlen(line) == 0)
		print_error();
}

void
	do_operation(char *line, t_stack **stack_a, t_stack **stack_b)
{
	line_length_check(line);
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		sa(stack_a);
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		sb(stack_b);
	else if (!ft_strncmp(line, "ss", ft_strlen(line)))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		ra(stack_a);
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		rb(stack_b);
	else if (!ft_strncmp(line, "rr", ft_strlen(line)))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		rra(stack_a);
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		rrb(stack_b);
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
		rrr(stack_a, stack_b);
	else
		print_error();
}

void
	handle_exception(int ac, char **av)
{
	if (ac == 1)
		exit(0);
	if (!ft_strncmp(av[1], "-", ft_strlen(av[1])) || \
		!ft_strncmp(av[1], "+", ft_strlen(av[1])))
		print_error();
}

int
	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	handle_exception(ac, av);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack();
	stack_b = init_stack();
	parse(av, &stack_a);
	while (get_next_line(0, &line) > 0)
	{
		do_operation(line, &stack_a, &stack_b);
		free(line);
		line = NULL;
	}
	if (*line)
	{
		do_operation(line, &stack_a, &stack_b);
		free(line);
	}
	if (is_sorted(&stack_a, stack_a->size) && stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
