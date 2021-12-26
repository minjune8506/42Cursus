/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:08 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/26 18:28:09 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_state(int ac, char **av, t_state *state);
void	parse_input(int ac, char **av, t_state *state);
void	init_philo(t_state *state, t_philo *philos);

int
	init(int ac, char **av, t_state *state)
{
	if (init_state(ac, av, state))
		return (EXIT_FAILURE);
	init_philo(state, state->philos);
	return (EXIT_SUCCESS);
}

int
	init_state(int ac, char **av, t_state *state)
{
	int	i;

	i = 0;
	parse_input(ac, av, state);
	state->running = 1;
	state->philos = (t_philo *)malloc(sizeof(t_philo) * state->num_philo);
	if (!state->philos)
		return (EXIT_FAILURE);
	state->forks_lock = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * state->num_philo);
	if (!state->forks_lock)
		return (EXIT_FAILURE);
	state->th_id = (pthread_t *)malloc(sizeof(pthread_t) * state->num_philo);
	if (!state->th_id)
		return (EXIT_FAILURE);
	while (i < state->num_philo)
	{
		if (pthread_mutex_init(&state->forks_lock[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&state->display_lock, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void
	parse_input(int ac, char **av, t_state *state)
{
	state->num_philo = ft_atoi(av[1]);
	state->time_to_die = ft_atoi(av[2]);
	state->time_to_eat = ft_atoi(av[3]);
	state->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		state->must_eat = ft_atoi(av[5]);
	else
		state->must_eat = 0;
}

void
	init_philo(t_state *state, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < state->num_philo)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = i;
		philos[i].right_fork = i + 1;
		if (philos[i].right_fork == state->num_philo)
			philos[i].right_fork = 0;
		philos[i].eat_count = 0;
		philos[i].deadline = 0;
		philos[i].last_eat = 0;
		philos[i].finished = 0;
		philos[i].state = state;
		i++;
	}
}
