#include "philo.h"

size_t	get_curr_time(void)
{
	struct	timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error getting time\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000)); // Fixed tv_usec typo
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
			pthread_mutex_lock(&prog->philos[i].meal_lock); // Lock before reading last_meal
			
			if (get_curr_time() - prog->philos[i].last_meal >= prog->time_to_die)
			{
				// Set dead flag safely
				pthread_mutex_lock(&prog->dead_lock);
				prog->dead_flag = 1;
				pthread_mutex_unlock(&prog->dead_lock);

				// Print death message safely
				pthread_mutex_lock(&prog->write_lock);
				printf("%zu %d died\n", get_curr_time(), prog->philos[i].id);
				// Do NOT unlock write_lock here so no one else can print after death

				pthread_mutex_unlock(&prog->philos[i].meal_lock);
				return;
			}
			
			if (prog->num_times_to_eat != -1 && prog->philos[i].meals_eaten < prog->num_times_to_eat)
				all_full = 0;
			
			pthread_mutex_unlock(&prog->philos[i].meal_lock); // Unlock here!
			i++;
		}
		if (prog->num_times_to_eat != -1 && all_full == 1)
		{
			pthread_mutex_lock(&prog->dead_lock);
			prog->dead_flag = 1;
			pthread_mutex_unlock(&prog->dead_lock);
			return;
		}
		usleep(1000); // Small sleep prevents checking 10 million times per second
	}
}

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

// 1. A better sleep function. Standard usleep is inaccurate and can cause accidental deaths.
void	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < milliseconds)
		usleep(500);
}

// 2. A safe way for the philosopher to check if someone died before taking an action.
int	check_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->prog->dead_lock);
	dead = philo->prog->dead_flag;
	pthread_mutex_unlock(&philo->prog->dead_lock);
	return (dead);
}

// 3. A safe print function that checks the dead_flag and uses the write_lock.
void	print_msg(char *str, t_philo *philo)
{
	if (check_dead(philo))
		return ;
	pthread_mutex_lock(&philo->prog->write_lock);
	// Double check the dead flag inside the lock to be absolutely sure
	if (!philo->prog->dead_flag)
		printf("%zu %d %s\n", get_curr_time(), philo->id, str);
	pthread_mutex_unlock(&philo->prog->write_lock);
}

// 4. THE COMPLETED ROUTINE
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	// Deadlock prevention: delay even-numbered philosophers slightly so 
	// they don't all grab the left fork at the exact same millisecond.
	if (philo->id % 2 == 0)
		ft_usleep(1);

	while (!check_dead(philo))
	{
		// 1. Take left fork
		pthread_mutex_lock(philo->l_fork);
		print_msg("has taken a fork", philo);
		
		// Edge case: If there is only 1 philosopher, there is only 1 fork. 
		// They will starve waiting for a right fork that doesn't exist.
		if (philo->prog->num_of_philos == 1)
		{
			ft_usleep(philo->prog->time_to_die);
			pthread_mutex_unlock(philo->l_fork);
			break ;
		}

		// 2. Take right fork
		pthread_mutex_lock(philo->r_fork);
		print_msg("has taken a fork", philo);

		// 3. EAT
		print_msg("is eating", philo);
		pthread_mutex_lock(&philo->meal_lock);
		philo->last_meal = get_curr_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_lock);
		ft_usleep(philo->prog->time_to_eat); // Eat for time_to_eat ms

		// 4. Drop forks
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);

		// Check if we hit the optional meal limit to break out early
		if (philo->prog->num_times_to_eat != -1 
			&& philo->meals_eaten >= philo->prog->num_times_to_eat)
			break ;

		// 5. SLEEP
		print_msg("is sleeping", philo);
		ft_usleep(philo->prog->time_to_sleep); // Sleep for time_to_sleep ms

		// 6. THINK
		print_msg("is thinking", philo);
	}
	return (NULL);
}

int	simulation(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->num_of_philos)
	{
		if (pthread_create(&prog->philos[i].thread_id, NULL, &philo_routine, &prog->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

void	cleanup(t_program *prog)
{
	int i;

	i = 0;
	while (i < prog->num_of_philos)
	{
		pthread_mutex_destroy(&prog->forks[i]);
		pthread_mutex_destroy(&prog->philos[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->write_lock);
	free(prog->philos);
	free(prog->forks);
}

int	philosopher(char *argv[], int argc)
{
	t_program	prog;
	int			i;

	if (init_prog(&prog, argv + 1, argc) != 0)
		return (1);
	if (init_philos_and_forks(&prog) != 0)
		return (1);
	if (simulation(&prog) != 0)
		return (1);
		
	monitor(&prog);
	
	i = 0;
	while (i < prog.num_of_philos)
	{
		pthread_join(prog.philos[i].thread_id, NULL);
		i++;
	}
	
	cleanup(&prog);
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (1);
	if (!check_input(argv + 1, argc))
		return (1);
	if (philosopher(argv, argc) != 0)
		return (1);
	return (0);
}