#include "./include/philo.h"

int	main(int argc, char **argv)
{
	if (!valid_input(argv + 1, argc))
		return (1);
	if (philosopher(argc, argv) != 0)
		return (1);
}
