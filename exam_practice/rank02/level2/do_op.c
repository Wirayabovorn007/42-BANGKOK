#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 4 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}

	int	x = atoi(argv[1]);
	int y = atoi(argv[3]);

	char op = argv[2][0];

	if (op == '+')
		printf("%d\n", x+y);
	if (op == '-')
		printf("%d\n", x-y);
	if (op == '*')
		printf("%d\n", x*y);
	if (op == '/')
		printf("%d\n", x/y);
	return 0;
}