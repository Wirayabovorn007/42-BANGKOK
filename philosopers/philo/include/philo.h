#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	meal_lock;
	t_prog		*prog;
} t_philo;


typedef struct s_program
{
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	int				dead_flag;
	size_t			start_time;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
} t_prog;

int	valid_input(char **argv, int argc);
int	philosopher(int argc, char **argv);
int	ft_atoi(char *str);
size_t	get_current_time(void);
void init_program(t_prog *program, char **argv, int argc);
int	init_philos_and_forks(t_prog *program);
void	ft_usleep(size_t milisec);
int	is_dead(t_philo *philo);
void	print_msg(char *str, t_philo *philo);
void	cleanup(t_prog *prog);

#endif
