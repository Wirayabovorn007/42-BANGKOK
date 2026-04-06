#include "./include/philo.h"

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

int	main(int argc, char **argv)
{
	if (valid_input(argv + 1, argc) != 0)
		return (1);
	if (philosopher(argc, argv) != 0)
		return (1);
	return (0);
}
