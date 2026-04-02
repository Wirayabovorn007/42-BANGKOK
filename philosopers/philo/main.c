
#include "philo.h"

size_t	get_curr_time()
{
	struct	timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error getting time\n");
	return ((time.tv_sec * 1000) + (time.tv_sec / 1000));
}

void	monitor(t_program *prog)
{
	int	i;
	int	all_full;

	while (1)
	{
		i = 0;
		all_full = 1;

		while (i < prog->num_of_philos)
		{
			pthread_mutex_lock(&prog->philos[i].meals_eaten);
			if (get_curr_time() - prog->philos[i].last_meal >= prog->time_to_die)
			{
				// pthread_mutex_unlock(&prog->philos[i].meal_lock) --> meal_lock doesn't exist
			}
			if (prog->num_times_to_eat != -1 && prog->philos[i].meals_eaten < prog->num_times_to_eat)
				all_full = 0;
			i++;
		}
		if (prog->num_times_to_eat != -1 && all_full == 1)
        {
            return;
        }
	}
}


void	init_prog(t_program *prog, char *argv[], int argc)
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
	pthread_mutex_init(&prog->dead_lock, NULL);
	pthread_mutex_init(&prog->write_lock, NULL);

	return (0);
}

void	init_philos_and_forks(t_program *prog)
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
		prog->philos[i].prog = prog;
		prog->philos[i].l_fork = &prog->forks[i];
		prog->philos[i].r_fork = &prog->forks[(i + 1) % prog->num_of_philos];
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	printf("Philosopher %d has starting their routine!\n", philo->id);

	return (NULL);
}

int	simulation(t_program *prog)
{
	int	i;
	pthread_t	thread_id;

	i = 0;
	while (i < prog->num_of_philos)
	{
		if (pthread_create(&thread_id, NULL, &philo_routine, &prog->philos[i] != 0))
			return (1);
		i++;
	}
	return (0);
}

int	philosopher(char *argv[], int argc)
{
	t_program	prog;

	init_prog(&prog, argv + 1, argc);
	init_philos_and_forks(&prog);
}


int main(int argc, char *argv[])
{
	// check error
	if (argc < 5 || argc > 6)
		return (1);
	if (!check_input(argv + 1, argc))
		return (1);
	if (philosopher(argv, argc) != 0)
		return (1);
}
