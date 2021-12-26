/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:31:19 by minjkim2          #+#    #+#             */
/*   Updated: 2021/12/26 18:31:20 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define RESET "\x1b[0m"
# define RED "\x1b[31m"
# define BLUE "\x1b[34m"

# include <stdlib.h>
# include <pthread.h>

struct	s_state;

typedef struct s_philo
{
	int					id;
	int					left_fork;
	int					right_fork;
	int					eat_count;
	unsigned long long	deadline;
	unsigned long long	last_eat;
	int					is_eating;
	int					finished;
	struct s_state		*state;
}t_philo;

typedef struct s_state
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	short			running;
	t_philo			*philos;
	pthread_t		*th_id;
	pthread_t		monitor;
	uint64_t		start;
	pthread_mutex_t	*forks_lock;
	pthread_mutex_t	display_lock;
}t_state;

/*
check.c
*/
int			check_args(int ac, char **av);
/*
init.c
*/
int			init(int ac, char **av, t_state *state);
/*
thread.c
*/
int			init_thread(t_state *state);
/*
monitor.c
*/
void		*monitor(void *arg);
/*
utils.c
*/
void		grab_fork(t_state *state, int c);
void		down_fork(t_state *state, int c1, int c2);
uint64_t	get_time(void);
void		print_message(t_philo *philo, int type);
void		ft_usleep(t_philo *philo, int time);
/*
ft_atoi.c
*/
int			ft_atoi(const char *str);
#endif
