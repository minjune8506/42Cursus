#include "philo.h"
#include <stdio.h>

void		print_data(t_state state);

int main(int ac, char **av)
{
	t_state state;

	if (check_args(ac, av))
		return (EXIT_FAILURE);
	init(ac, av, &state);
	// print_data(state);
	init_thread(&state);
}

void print_data(t_state state)
{
	printf("num_philo : %d\n", state.num_philo);
	printf("time_to_die : %d\n", state.time_to_die);
	printf("time_to_eat : %d\n", state.time_to_eat);
	printf("time_to_sleep : %d\n", state.time_to_sleep);
	printf("must_eat : %d\n", state.must_eat);
	int i = 0;
	while (i < state.num_philo)
	{
		printf("id : %d\n", state.philos[i].id);
		printf("left_fork : %d\n", state.philos[i].left_fork);
		printf("right_fork : %d\n", state.philos[i].right_fork);
		printf("eat_count : %d\n", state.philos[i].eat_count);
		printf("check_connect : %d\n", state.philos[i].state->num_philo);
		i++;
	}
}

