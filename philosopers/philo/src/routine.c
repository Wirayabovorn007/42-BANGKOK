#include "../include/philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken a fork", philo);
	if (philo->prog->num_of_philos == 1)
	{
		ft_usleep(philo->prog->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo);
	return (0);
}

void	eating(t_philo *philo)
{
	print_msg("is eating", philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->prog->time_to_eat);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id %2 == 0)
		ft_usleep(1);
	while (!is_dead(philo))
	{
		if (take_forks(philo) != 0)
			break ;
		eating(philo);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		print_msg("is sleeping", philo);
		ft_usleep(philo->prog->time_to_sleep);
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
