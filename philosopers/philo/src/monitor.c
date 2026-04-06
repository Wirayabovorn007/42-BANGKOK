#include "../include/philo.h"

int	reach_time_to_die(t_prog *prog, int i)
{
	if (get_current_time() - prog->philos[i].last_meal >= prog->time_to_die)
	{
		pthread_mutex_lock(&prog->dead_lock);
		prog->dead_flag = 1;
		pthread_mutex_unlock(&prog->dead_lock);
		pthread_mutex_lock(&prog->write_lock);
		printf("%zu %d died\n", get_current_time() - prog->start_time, prog->philos[i].id);
		pthread_mutex_unlock(&prog->write_lock);
		pthread_mutex_unlock(&prog->philos[i].meal_lock);
		return (1);
	}
	return (0);
}

int	reach_times_to_eat(t_prog *prog, int all_full)
{
	if (prog->num_times_to_eat != -1 && all_full == 1)
	{
		pthread_mutex_lock(&prog->dead_lock);
		prog->dead_flag = 1;
		pthread_mutex_unlock(&prog->dead_lock);
		return (1);
	}
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
			pthread_mutex_lock(&prog->philos[i].meal_lock);
			if (reach_time_to_die(prog, i))
				return ;
			if (prog->num_times_to_eat != -1
				&& prog->philos[i].meals_eaten < prog->num_times_to_eat)
				all_full = 0;
			pthread_mutex_unlock(&prog->philos[i].meal_lock);
		}
		if (reach_times_to_eat(prog, all_full))
			return ;
		usleep(1000);
	}
}
