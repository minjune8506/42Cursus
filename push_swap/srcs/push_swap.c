#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"

void	print_stack(t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	if (stack->size == 0)
	{
		printf("empty\n");
		return ;
	}
	temp = stack->top;
	while (i < stack->size)
	{
		printf("%-3d", temp->data);
		temp = temp->next;
		i++;
	}
	printf("\n");
}

void	print_all(t_stack **stack_a, t_stack **stack_b)
{
	printf("stack_a : ");
	print_stack(*stack_a);
	printf("stack_b : ");
	print_stack(*stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(stack_a);
	stack_b = init_stack(stack_b);
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
