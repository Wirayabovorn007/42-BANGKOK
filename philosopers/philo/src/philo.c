#include "philo.h"

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
				printf("%zu %d died\n", get_curr_time() - prog->start_time, prog->philos[i].id);
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
