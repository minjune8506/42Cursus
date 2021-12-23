#include "philo.h"

void init_state(int ac, char **av, t_state *state);
void init_philo(t_state *state, t_philo *philos);

void init(int ac, char **av, t_state *state)
{
	init_state(ac, av, state);
	init_philo(state, state->philos);
}

void init_state(int ac, char **av, t_state *state)
{
	int i;

	i = 0;
	state->num_philo = ft_atoi(av[1]);
	state->time_to_die = ft_atoi(av[2]);
	state->time_to_eat = ft_atoi(av[3]);
	state->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		state->must_eat = ft_atoi(av[5]);
	else
		state->must_eat = 0;
	state->philos = (t_philo *)malloc(sizeof(t_philo) * state->num_philo);
	state->forks_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * state->num_philo);
	while (i < state->num_philo)
	{
		pthread_mutex_init(&state->forks_lock[i], NULL);
		i++;
	}
	pthread_mutex_init(&state->display_lock, NULL);
}

void init_philo(t_state *state, t_philo *philos)
{
	int i;

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
		philos[i].state = state;
		i++;
	}
}
