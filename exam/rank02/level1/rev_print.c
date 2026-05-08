

int	len(char *str)
{
	int i;

	i = -1;
	while (str[++i]);
	return i;
}

#include <unistd.h>
int main(int argc, char *argv[])
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}
	int size = len(argv[1]);
	char *str = argv[1];
	size--;
	while (size >= 0)
	{
		write(1, &str[size], 1);
		size--;
	}
	write(1, "\n", 1);
	return 0;
}
