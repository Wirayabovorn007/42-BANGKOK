
#include "philo.h"

void philosopher(char *argv[])
{
	
}

int main(int argc, char *argv[])
{
	// check error
	if (argc - 1 < 4)
		return (1);
	argv++;
	philosopher(argv);
}
