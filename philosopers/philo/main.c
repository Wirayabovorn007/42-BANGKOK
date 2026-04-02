
#include "philo.h"

void	init(t_program *prog, char *argv[])
{
	int		opt_arg_val;
	t_philo	*philos;

	philos = prog->philos;
	philos[ft_atoi(argv[0])];
	opt_arg_val = 0;
	if (argv[4])
		opt_arg_val = argv[4];
	philos->number_of_philo = ft_atoi(argv[0]);
	philos->time_to_die = ft_atoi(argv[1]);
	philos->time_to_eat = ft_atoi(argv[2]);;
	philos->time_to_sleep = ft_atoi(argv[3]);
	philos->times_philo_eat = opt_arg_val;
}

void philosopher(char *argv[])
{
	t_program	prog;

	init(&prog, argv);
}


int main(int argc, char *argv[])
{
	// check error
	if (argc - 1 < 4)
		return (1);
	argv++;
	if (!check_input(argv, argc))
		return (1);
	philosopher(argv);
}
