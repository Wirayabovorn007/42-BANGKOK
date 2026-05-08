#include <unistd.h>


int main(int argc, char *argv[])
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}
	char *str = argv[1];
	char c;
	while (*str)
	{
		c = *str;
		if (c >= 'a' && c <= 'z')
		{
			c -= 32;
			write(1, &c, 1);
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c += 32;
			write(1, &c, 1);
		}
		str++;
	}
	write(1, "\n", 1);
	return 0;
}