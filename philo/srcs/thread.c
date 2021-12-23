#include "philo.h"
#include <unistd.h>

void	*philosopher(void *arg);
void	*monitor(void *arg);
void	even_philo(t_philo *philo);
void	odd_philo(t_philo *philo);

int init_thread(t_state *state)
{
	pthread_t *th_id;
	void *retval;
	int i;

	i = 0;
	th_id = (pthread_t *)malloc(sizeof(pthread_t) * state->num_philo);
	state->start = get_time();
	state->running = 1;
	while (i < state->num_philo)
	{
		pthread_create(&th_id[i], NULL, philosopher, &state->philos[i]);
		i++;
	}
	i = 0;
	while (i < state->num_philo)
	{
		pthread_join(th_id[i], &retval);
		i++;
	}
}

void *philosopher(void *arg)
{
	t_philo *philo;
	pthread_t th_id;
	void *retval;

	philo = (t_philo *)arg;
	// printf("%lld Philosopher %d is ready\n",(get_time() - philo.state->start), philo.id);
	philo->last_eat = get_time();
	philo->deadline = philo->last_eat + philo->state->time_to_die;
	pthread_create(&th_id, NULL, &monitor, philo);
	while (1)
	{
		if (philo->state->running == 0)
			break;
		if (philo->id % 2 == 0)
			even_philo(philo);
		else
			odd_philo(philo);
	}
}

void *monitor(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (!philo->is_eating && get_time() > philo->deadline)
		{
			// Philo is dead case
			print_message(philo, DEAD);
			philo->state->running = 0;
			break;
		}
		usleep(1000);
	}
}

void even_philo(t_philo *philo)
{
	grab_fork(philo->state, philo->right_fork);
	grab_fork(philo->state, philo->left_fork);
	print_message(philo, FORK);
	print_message(philo, EAT);

	philo->is_eating = 1;
	usleep(philo->state->time_to_eat * 1000);
	philo->last_eat = get_time();
	philo->deadline = philo->last_eat + philo->state->time_to_die;

	down_fork(philo->state, philo->right_fork, philo->left_fork);

	print_message(philo, SLEEP);
	usleep(philo->state->time_to_sleep * 1000);
}

void odd_philo(t_philo *philo)
{
	grab_fork(philo->state, philo->left_fork);
	grab_fork(philo->state, philo->right_fork);

	print_message(philo, FORK);
	print_message(philo, EAT);
	philo->is_eating = 1;
	usleep(philo->state->time_to_eat * 1000);
	philo->last_eat = get_time();
	philo->deadline = philo->last_eat + philo->state->time_to_die;
	down_fork(philo->state, philo->right_fork, philo->left_fork);

	print_message(philo, SLEEP);
	usleep(philo->state->time_to_sleep * 1000);
}
