#include "philo.h"

int main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (1);
	if (!check_input(argv + 1, argc))
		return (1);
	if (philosopher(argv, argc) != 0)
		return (1);
	return (0);
}