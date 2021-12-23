#include "philo.h"
#include <sys/time.h>
#include <stdio.h>

void	grab_fork(t_state *state, int c)
{
	pthread_mutex_lock(&state->forks_lock[c]);
}

void	down_fork(t_state *state, int c1, int c2)
{
		pthread_mutex_unlock(&state->forks_lock[c1]);
		pthread_mutex_unlock(&state->forks_lock[c2]);
}

uint64_t get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	print_message(t_philo *philo, int type)
{
	if (philo->state->running == 0)
		return ;
	pthread_mutex_lock(&philo->state->display_lock);
	printf(BLUE"%lld\t"RESET, get_time() - philo->state->start);
	printf("Philosopher %d", philo->id);
	if (type == FORK)
		printf(" has taken a fork\n");
	else if (type == EAT)
		printf(" is eating\n");
	else if (type == SLEEP)
		printf(" is sleeping\n");
	else if (type == THINK)
		printf(" is thinking\n");
	else if (type == DEAD)
			printf(RED" is dead\n"RESET);
	pthread_mutex_unlock(&philo->state->display_lock);
}
