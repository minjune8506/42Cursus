/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:44:20 by minjkim2          #+#    #+#             */
/*   Updated: 2021/08/07 23:44:21 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*tail;
	int		size;
}t_stack;

t_stack		*init_stack(void);
t_node		*init_node(int data);
void		parse(char **av, t_stack **stack_a);
void		check_valid(char **av);
void		check_range(char **av);
void		check_overlap(int *arr, int size);
void		print_error(void);
void		split_free(char **str);
int			is_space(char c);
long long	ft_atoi_long(const char *str);
void		push(t_stack *stack, int data);
void		push_back(t_stack *stack, int data);
t_node		*pop(t_stack *stack);
t_node		*pop_back(t_stack *stack);
void		destroy_stack(t_stack *stack);
int			get_next_line(int fd, char **line);
char		*ft_strjoin_free(char *s1, char *s2);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
#endif
