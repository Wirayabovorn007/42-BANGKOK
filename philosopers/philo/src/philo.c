#include "../include/philo.h"


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id %2 == 0)
		ft_usleep(1);
	while (!is_dead(philo))
	{
		// take the left fork
		pthread_mutex_lock(philo->l_fork);
		print_msg("has taken a fork", philo);

		// check edge case (1 philosopher)
		if (philo->prog->num_of_philos == 1)
		{
			ft_usleep(philo->prog->time_to_die);
			pthread_mutex_unlock(philo->l_fork);
			break ;
		}
		// take the right fork
		pthread_mutex_lock(philo->r_fork);
		print_msg("has taken a fork", philo);

		// start eating
		print_msg("is eating", philo);
		pthread_mutex_lock(&philo->meal_lock);
		philo->last_meal = get_current_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_lock);
		ft_usleep(philo->prog->time_to_eat);

		// drop forks
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);

		// check if we hit optional meal limit to break out early
		if (philo->prog->num_times_to_eat != -1
			&& philo->meals_eaten >= philo->prog->num_times_to_eat)
			break ;
		
		// sleep
		print_msg("is sleeping", philo);
		ft_usleep(philo->prog->time_to_sleep);
		
		// think
		print_msg("is thinking", philo);
	}
	return (NULL);
}

int	simulation(t_prog *prog)
{
	int	i;

	i = -1;
	while (++i < prog->num_of_philos)
		if (pthread_create(&prog->philos[i].thread_id, NULL,
			&routine, &prog->philos[i]) != 0)
			return (1);
	return (0);
}

void	monitor(t_prog *prog)
{
	int	i;
	int	all_full;

	while (1)
	{
		i = -1;
		all_full = 1;
		while (++i < prog->num_of_philos)
		{
			pthread_mutex_lock(&prog->philos[i].last_meal);
			if (get_current_time() - prog->philos[i].last_meal >= prog->time_to_die)
			{
				pthread_mutex_lock(&prog->dead_lock);
				prog->dead_flag = 1;
				pthread_mutex_unlock(&prog->dead_lock);

				pthread_mutex_lock(&prog->write_lock);
				printf("%zu %d died\n", get_current_time() - prog->start_time, prog->philos[i].id);
				//do not unlock write_lock here to prevent other philo print message after death
				pthread_mutex_unlock(&prog->dead_lock);
				return ;
			}
			if (prog->num_times_to_eat != -1 && prog->philos[i].meals_eaten < prog->num_times_to_eat)
				all_full = 0;
			pthread_mutex_unlock(&prog->write_lock);
		}
		if (prog->num_times_to_eat != -1 && all_full == 1)
		{
			pthread_mutex_lock(&prog->dead_lock);
			prog->dead_flag = 1;
			pthread_mutex_unlock(&prog->dead_lock);
			return ;
		}
		usleep(1000);
	}
}

int philosopher(int argc, char **argv)
{
	int	i;
	t_prog	program;

	init_program(&program, argv + 1, argc);
	if (init_philos_and_forks(&program) != 0)
		return (1);
	if (simulation(&program) != 0)
		return (1);
	monitor(&program);
	i = -1;
	while (++i < program.num_of_philos)
		pthread_join(program.philos[i].thread_id, NULL);
	cleanup(&program);
	return (0);
}
