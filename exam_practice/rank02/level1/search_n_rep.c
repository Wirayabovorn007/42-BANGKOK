
#include <unistd.h>

int is_sub(char *found, char *src)
{
	int	i;
	i = 0;
	while (src[i])
	{
		if (found[i] != src[i])
			return 0;
		i++;
	}
	return (1);
}

void	print_na(char *str)
{
	int i =0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	char*search;
	char*replace;
	char *str;

	if (argc != 4 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}
	str = argv[1];
	search = argv[2];
	replace = argv[3];
	int has_sub = 0;
	while (*str) //if not contain any of substr
	{
		if (is_sub(str, search))
		{
			has_sub++;
			break ;
		}
		str++;
	}
	if (!has_sub)
	{
		write(1, "\n", 1);
		return 1;
	}
	str = argv[1];
	while (*str)
	{
		if (*str == *search)
		{
			if (is_sub(str, search))
			{
				print_na(replace);
				str++;
				continue ;
			}
		}
		write(1, &(*str), 1);
		str++;
	}
	print_na("\n");
}