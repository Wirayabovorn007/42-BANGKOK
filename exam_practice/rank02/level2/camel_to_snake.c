#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}

	int i =0;
	char *str = argv[1];
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			write(1, "_", 1);
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}