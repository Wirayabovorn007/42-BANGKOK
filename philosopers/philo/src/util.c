#include "../include/philo.h"


void	ft_usleep(size_t milisec)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milisec)
		usleep(500);
}

int	is_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->prog->dead_lock);
	dead = philo->prog->dead_flag;
	pthread_mutex_unlock(&philo->prog->dead_lock);
	return (dead);
}

void	print_msg(char *str, t_philo *philo)
{
	size_t	time;

	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->prog->write_lock);
	if (!philo->prog->dead_flag)
	{
		time = get_current_time() - philo->prog->start_time;
		printf("%zu %d %s\n", time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->prog->write_lock);
}

void	cleanup(t_prog *prog)
{
	int	i;

	i = -1;
	while (++i < prog->num_of_philos)
	{
		pthread_mutex_destroy(&prog->forks[i]);
		pthread_mutex_destroy(&prog->philos[i].meal_lock);
	}
	pthread_mutex_destroy(&prog->dead_lock);
	pthread_mutex_destroy(&prog->write_lock);
	free(prog->philos);
	free(prog->forks);
}
