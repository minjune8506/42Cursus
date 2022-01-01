/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:22 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/26 18:28:22 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	check_live(t_state *state, t_philo *philos);
void	check_philo(t_state *state, t_philo *philos, int *flag);

void
	*monitor(void *arg)
{
	t_philo	*philos;
	t_state	*state;
	int		flag;

	state = (t_state *)arg;
	philos = state->philos;
	while (1)
	{
		flag = 0;
		check_live(state, philos);
		check_philo(state, philos, &flag);
		if (!state->running)
			break ;
		if (!flag)
		{
			state->running = 0;
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void
	check_live(t_state *state, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < state->num_philo)
	{
		if (get_time() > philos[i].deadline)
		{
			print_message(&philos[i], DEAD);
			state->running = 0;
			break ;
		}
		if (philos[i].eat_count >= state->must_eat)
			philos[i].finished = 1;
		i++;
	}
}

void
	check_philo(t_state *state, t_philo *philos, int *flag)
{
	int	i;

	i = 0;
	while (i < state->num_philo)
	{
		if (!philos[i].finished || !state->must_eat)
		{
			*flag = 1;
			break ;
		}
		i++;
	}
}
