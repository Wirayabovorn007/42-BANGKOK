#include "../include/philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error getting time\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void init_program(t_prog *program, char **argv, int argc)
{
	program->num_of_philos = ft_atoi(argv[0]);
	program->time_to_die = ft_atoi(argv[1]);
	program->time_to_eat = ft_atoi(argv[2]);
	program->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 6)
		program->num_times_to_eat = ft_atoi(argv[4]);
	else
		program->num_times_to_eat = -1;
	program->dead_flag = 0;
	program->start_time = get_current_time();
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}

int	init_philos_and_forks(t_prog *program)
{
	int	i;

	program->philos = malloc(sizeof(t_philo) * program->num_of_philos);
	program->forks = malloc(sizeof(pthread_mutex_t) * program->num_of_philos);
	if (!program->philos || !program->forks)
		return (1);
	i = -1;
	while (++i < program->num_of_philos)
		pthread_mutex_init(&program->forks[i], NULL);
	i = -1;
	while (++i < program->num_of_philos)
	{
		program->philos[i].id = i + 1;
		program->philos[i].meals_eaten = 0;
		program->philos[i].last_meal = get_current_time();
		program->philos[i].prog = program;
		program->philos[i].l_fork = &program->forks[i];
		program->philos[i].r_fork = &program->forks[(i + 1) % program->num_of_philos];
		pthread_mutex_init(&program->philos[i].meal_lock, NULL);
	}
	return (0);
}
