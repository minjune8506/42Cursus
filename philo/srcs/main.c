/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:28:13 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/26 18:28:14 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_state *state);

int
	main(int ac, char **av)
{
	t_state	state;

	if (check_args(ac, av))
		return (EXIT_FAILURE);
	if (init(ac, av, &state))
		return (EXIT_FAILURE);
	if (init_thread(&state))
		return (EXIT_FAILURE);
	free_all(&state);
}

void
	free_all(t_state *state)
{
	int	i;

	i = 0;
	free(state->philos);
	free(state->th_id);
	while (i < state->num_philo)
		pthread_mutex_destroy(&state->forks_lock[i++]);
	pthread_mutex_destroy(&state->display_lock);
}
