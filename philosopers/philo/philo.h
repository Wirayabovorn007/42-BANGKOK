#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>


typedef struct s_philo {
	int				id;                 // Philosopher number (1 to N)
	int				meals_eaten;        // Track how many times they ate
	size_t			last_meal;          // Timestamp of the last meal
	pthread_mutex_t	*l_fork;            // Pointer to left fork mutex
	pthread_mutex_t	*r_fork;            // Pointer to right fork mutex
	t_program		*prog;              // Pointer to the shared program data
}	t_philo;

typedef struct s_program {
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;   // -1 if not specified
	int				dead_flag;          // 1 if someone died, 0 otherwise
	pthread_mutex_t	dead_lock;          // Protects dead_flag
	pthread_mutex_t	write_lock;         // Protects printf outputs
	pthread_mutex_t	*forks;             // Array of fork mutexes
	t_philo			*philos;            // Array of philosophers
}	t_program;


int	check_input(char *argv[], int argc);
int	ft_atoi(const char *str);

#endif