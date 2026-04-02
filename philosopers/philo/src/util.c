#include "philo.h"

size_t	get_curr_time(void)
{
	struct	timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error getting time\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000)); // Fixed tv_usec typo
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
	size_t	time; // Variable to hold the relative time

	if (check_dead(philo))
		return ;
	pthread_mutex_lock(&philo->prog->write_lock);
	if (!philo->prog->dead_flag)
	{
		// Calculate relative time: Current Time - Start Time
		time = get_curr_time() - philo->prog->start_time;
		printf("%zu %d %s\n", time, philo->id, str); // Print the calculated time
	}
	pthread_mutex_unlock(&philo->prog->write_lock);
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