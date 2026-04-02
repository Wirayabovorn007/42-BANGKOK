#include "philo.h"

int	init_prog(t_program *prog, char *argv[], int argc)
{
	prog->num_of_philos = ft_atoi(argv[0]);
	prog->time_to_die = ft_atoi(argv[1]);
	prog->time_to_eat = ft_atoi(argv[2]);
	prog->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 6)
		prog->num_times_to_eat = ft_atoi(argv[4]);
	else
		prog->num_times_to_eat = -1;
	prog->dead_flag = 0;
	prog->start_time = get_curr_time();
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);

	return (0);
}

int	init_philos_and_forks(t_program *prog)
{
	int	i;

	prog->philos = malloc(sizeof(t_philo) * prog->num_of_philos);
	prog->forks = malloc(sizeof(pthread_mutex_t) * prog->num_of_philos);
	if (!prog->philos || !prog->forks)
		return (1);
	i = 0;
	while (i < prog->num_of_philos)
	{
		pthread_mutex_init(&prog->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < prog->num_of_philos)
	{
		prog->philos[i].id = i + 1;
		prog->philos[i].meals_eaten = 0;
		prog->philos[i].last_meal = get_curr_time(); // Initialize last_meal
		prog->philos[i].prog = prog;
		prog->philos[i].l_fork = &prog->forks[i];
		prog->philos[i].r_fork = &prog->forks[(i + 1) % prog->num_of_philos];
		pthread_mutex_init(&prog->philos[i].meal_lock, NULL); // Initialize meal_lock
		i++;
	}
	return (0);
}