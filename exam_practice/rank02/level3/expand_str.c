#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (!argv[1] || argc != 2)
	{
		write(1, "\n", 1);
		return 1;
	}
	char *str = argv[1];
	int is_first = 1;

	while (*str == ' ' || *str == '\t')
			str++;

	while (*str)
	{
		if (!is_first)
			write(1, "   ",3);
		while (!(*str == ' ' || *str == '\t') && *str)
		{
			write(1, &(*str), 1);
			str++;
		}
		while (*str == ' ' || *str == '\t')
			str++;
		is_first = 0;
	}
	write(1, "\n", 1);
}