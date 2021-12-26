/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:30 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/26 18:28:30 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	*routine(void *arg);
void	do_routine(t_philo *philo);

int
	init_thread(t_state *state)
{
	int	i;

	i = 0;
	state->start = get_time();
	while (i < state->num_philo)
	{
		if (pthread_create(&state->th_id[i], NULL, routine, &state->philos[i]))
			return (EXIT_FAILURE);
		i++;
	}
	usleep(1000);
	if (pthread_create(&state->monitor, NULL, monitor, state))
		return (EXIT_FAILURE);
	i = 0;
	while (i < state->num_philo)
	{
		if (pthread_join(state->th_id[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_join(state->monitor, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void
	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->deadline = philo->state->start + philo->state->time_to_die;
	if (!philo->id % 2)
		usleep(100);
	while (1)
	{
		if (!philo->state->running || philo->state->num_philo == 1)
			break ;
		do_routine(philo);
	}
	return (NULL);
}

void
	do_routine(t_philo *philo)
{
	grab_fork(philo->state, philo->left_fork);
	grab_fork(philo->state, philo->right_fork);
	print_message(philo, FORK);
	print_message(philo, EAT);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->deadline = philo->last_eat + philo->state->time_to_die;
	ft_usleep(philo, philo->state->time_to_eat);
	down_fork(philo->state, philo->right_fork, philo->left_fork);
	philo->is_eating = 0;
	philo->eat_count++;
	print_message(philo, SLEEP);
	ft_usleep(philo, philo->state->time_to_sleep);
	print_message(philo, THINK);
}
