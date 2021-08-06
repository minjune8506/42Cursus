#include "push_swap.h"
#include <stdlib.h>

#include <stdio.h>

void
	push(t_stack *stack, int data)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = init_node(data);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->tail = new_node;
	}
	else
	{
		temp = stack->top;
		stack->top = new_node;
		new_node->next = temp;
		temp->prev = new_node;
	}
	stack->size++;
}

void
	push_back(t_stack *stack, int data)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = init_node(data);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->tail = new_node;
	}
	else
	{
		temp = stack->tail;
		stack->tail = new_node;
		new_node->prev = temp;
		temp->next = new_node;
	}
	stack->size++;
}

t_node
	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->top == NULL)
		return (NULL);
	else
	{
		node = stack->top;
		if (node->next)
		{
			stack->top = node->next;
			stack->top->prev = NULL;
		}
		else
		{
			stack->top = NULL;
			stack->tail = NULL;
		}
	}
	stack->size--;
	return (node);
}

t_node
	*pop_back(t_stack *stack)
{
	t_node	*node;

	if (stack->top == NULL)
		return (NULL);
	else
	{
		node = stack->tail;
		if (node->prev)
		{
			node->prev->next = NULL;
			stack->tail = node->prev;
		}
		else
		{
			stack->tail = NULL;
			stack->top = NULL;
		}
	}
	stack->size--;
	return (node);
}

void
	destroy_stack(t_stack *stack)
{
	t_node	*node;

	while (stack->size > 0)
	{
		node = pop(stack);
		free(node);
	}
	free(stack);
}
