/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:39 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/26 18:28:40 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void
	grab_fork(t_state *state, int c)
{
	pthread_mutex_lock(&state->forks_lock[c]);
}

void
	down_fork(t_state *state, int c1, int c2)
{
	pthread_mutex_unlock(&state->forks_lock[c1]);
	pthread_mutex_unlock(&state->forks_lock[c2]);
}

uint64_t
	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void
	print_message(t_philo *philo, int type)
{
	pthread_mutex_lock(&philo->state->display_lock);
	if (philo->state->running == 0)
	{
		pthread_mutex_unlock(&philo->state->display_lock);
		return ;
	}
	printf(BLUE"%lld"RESET, get_time() - philo->state->start);
	printf(" %d", philo->id);
	if (type == FORK)
		printf(" has taken a fork\n");
	else if (type == EAT)
		printf(" is eating\n");
	else if (type == SLEEP)
		printf(" is sleeping\n");
	else if (type == THINK)
		printf(" is thinking\n");
	else if (type == DEAD)
		printf(RED" died\n"RESET);
	pthread_mutex_unlock(&philo->state->display_lock);
}

void
	ft_usleep(t_philo *philo, int time)
{
	unsigned long long	now;

	now = get_time();
	while (get_time() < now + time)
	{
		if (!philo->state->running)
			break ;
		usleep(500);
	}
}
