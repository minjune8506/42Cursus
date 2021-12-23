#ifndef PHILO_H
# define PHILO_H

#define FORK 0
#define EAT 1
#define SLEEP 2
#define THINK 3
#define DEAD 4
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define BLUE "\x1b[34m"

#include <stdlib.h>
#include <pthread.h>

struct s_state;

typedef struct s_philo
{
	int id;
	int left_fork;
	int right_fork;
	int eat_count;
	unsigned long long deadline;
	unsigned long long last_eat;
	int is_eating;
	struct s_state *state;
} t_philo;

typedef struct s_state
{
	unsigned int num_philo;
	unsigned int time_to_die;
	unsigned int time_to_eat;
	unsigned int time_to_sleep;
	unsigned int must_eat;
	short running;

	t_philo *philos; // Heap
	uint64_t start;
	pthread_mutex_t *forks_lock; // Heap
	pthread_mutex_t display_lock; // stack
} t_state;


int			check_args(int ac, char **av);

void		init(int ac, char **av, t_state *state);

int			init_thread(t_state *state);

void		grab_fork(t_state *state, int c);
void		down_fork(t_state *state, int c1, int c2);
uint64_t	get_time(void);
void		print_message(t_philo *philo, int type);
int			ft_atoi(const char *str);
#endif
