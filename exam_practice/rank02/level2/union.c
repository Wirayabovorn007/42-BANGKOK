#include <unistd.h>

int	didnot_print(char c, char *str, int curr)
{
	int j = 0;
	while (j < curr)
	{
		if (c == str[j])
			return 0;
		j++;
	}
	return 1;
}

int is_in_first(char *s1, char c)
{
	int i =0;
	while (s1[i])
	{
		if (c == s1[i])
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
	int i = 0;
	char *s1 = argv[1];
	while (s1[i])
	{
		if (didnot_print(s1[i], s1, i))
			write(1, &s1[i], 1);
		i++;
	}

	i = 0;
	char*s2=argv[2];
	while (s2[i])
	{
		if (!is_in_first(s1, s2[i]) && didnot_print(s2[i], s2, i))
			write(1, &s2[i], 1);
		i++;
	}
	write(1, "\n",1 );
}