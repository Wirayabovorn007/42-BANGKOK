
#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;

	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}

	i=0;
	char c;
	char *str = argv[1];
	while (str[i])
	{
		c=str[i];
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			c = 90 - c + 65;
			write(1, &c, 1);
		}
		else if (c >= 'a' && c <= 'z')
		{
			c = 122 - c + 97;
			write(1, &c, 1);
		}
		i++;
	}
	write(1, "\n", 1);

	return 0;
}