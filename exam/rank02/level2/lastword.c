#include <unistd.h>

int str_len(char *str)
{
	int i = -1;
	while(str[++i]);
	return i;
}

int main(int argc, char *argv[])
{
	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}

	char *str = argv[1];
	int c = 0;
	int i = str_len(str) - 1;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && c) break ;
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			c = 1;
		i--;
	}
	i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}