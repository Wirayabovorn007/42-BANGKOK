#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>


typedef struct s_data{

} t_data

typedef struct s_philo {
	int number_of_philo;
	int*	philosophers;
	t_data	data;
	float	time_to_die;
	float	time_to_eat;
	float	time_to_sleep;
	int	times_each_philo_must_eat;
} t_philo;


#endif