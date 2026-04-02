#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

// 1. Forward declaration so t_philo knows about t_program
typedef struct s_program t_program;

typedef struct s_philo {
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	pthread_t		thread_id;          // Added to store the thread's ID
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	meal_lock;          // Added to prevent data races when reading/writing meals
	t_program		*prog;
}	t_philo;

typedef struct s_program {
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	int				dead_flag;
	size_t			start_time;         // <--- ADD THIS
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_program;


int	check_input(char *argv[], int argc);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	monitor(t_program *prog);
void	*philo_routine(void *arg);
int		simulation(t_program *prog);
int	philosopher(char *argv[], int argc);
int	init_prog(t_program *prog, char *argv[], int argc);
int	init_philos_and_forks(t_program *prog);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
int	is_num(char *s);
int	check_input(char *argv[], int argc);
size_t	get_curr_time(void);
void	ft_usleep(size_t milliseconds);
int	check_dead(t_philo *philo);
void	print_msg(char *str, t_philo *philo);
void	cleanup(t_program *prog);


#endif