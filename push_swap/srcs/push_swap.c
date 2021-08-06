#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack();
	stack_b = init_stack();
	parse(av, &stack_a);
	if (is_sorted(&stack_a, stack_a->size))
	{
		destroy_stack(stack_a);
		destroy_stack(stack_b);
		return (0);
	}
	a_to_b(&stack_a, &stack_b, stack_a->size);
	destroy_stack(stack_a);
	destroy_stack(stack_b);
}
