#include "push_swap.h"
#include <stdlib.h>

t_stack
	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		print_error();
	stack->size = 0;
	stack->top = NULL;
	stack->tail = NULL;
	return (stack);
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

t_node
	*init_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		print_error();
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
