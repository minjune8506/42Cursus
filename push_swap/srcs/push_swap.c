#include "push_swap.h"
#include <stdlib.h>

#include <stdio.h>

void	print_all(t_stack *stack_a, t_stack *stack_b)
{
	printf("stack_a : ");
	print_stack(stack_a);
	printf("stack_b : ");
	print_stack(stack_b);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = init_stack(stack_a);
	stack_b = init_stack(stack_b);
	parse(av, &stack_a);
	print_all(stack_a, stack_b);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	system("leaks push_swap");
}
