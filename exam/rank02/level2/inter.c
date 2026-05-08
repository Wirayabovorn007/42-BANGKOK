
#include <unistd.h>

int is_in(char *str, char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (c == str[i])
			return 1;
		i++;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}

	char *str = argv[1];
	char *str2 = argv[2];
	int  i = 0;
	int yep = 0;

	while (str[i])
	{
		int j = 0;
		while (j < i)
		{
			if (str[j] == str[i])
			{
				yep = 1;
				break ;
			}
			j++;
		}
		if (yep)
		{
			i++;
			yep = 0;
			continue ;
		}
		if (is_in(str2, str[i]))
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}