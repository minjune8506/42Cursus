#include "push_swap.h"
#include <stdlib.h>

void
	insertion_sort(int *list, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > key)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
		i++;
	}
}

int
	get_mid(t_stack **stack, int size)
{
	t_node		*node;
	int			*arr;
	int			mid;
	int			i;

	i = 0;
	node = (*stack)->top;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		print_error();
	while (node && i < size)
	{
		arr[i] = node->data;
		node = node->next;
		i++;
	}
	insertion_sort(arr, size);
	mid = arr[size / 2];
	free (arr);
	return (mid);
}
