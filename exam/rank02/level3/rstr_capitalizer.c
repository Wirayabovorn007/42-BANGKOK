

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}

	char *str = argv[1];
	int i =0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}