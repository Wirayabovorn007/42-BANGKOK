#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


typedef struct s_philo {
	int		idx;
	int number_of_philo;
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
	int		times_philo_eat;

	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;

typedef struct s_program
{
	t_philo	*philos;
}	t_program;


int	check_input(char *argv[], int argc);
int	ft_atoi(const char *str);

#endif