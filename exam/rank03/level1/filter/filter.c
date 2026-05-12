
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int is_heekuytad(char *str, char *format, int curr_i)
{
	int j = 0;

	while (format[j])
	{
		if (str[curr_i] != format[j]) return 0;
		j++;
		curr_i++;
	}
	return 1;
}

void print_star(int len_format)
{
	int i =-1;

	while (++i < len_format)
		printf("*");
}

void ft_filter(char *str, char *format)
{
	int i = 0;
	int len_format = strlen(format);

	while (str[i])
	{
		if (str[i] == format[0])
		{
			if (is_heekuytad(str, format, i))
			{
				print_star(len_format);
				i+=len_format;
				continue ;
			}
		}
		printf("%c", str[i]);
		i++;
	}
}

int main(int ac , char **av)
{
	if (ac != 2 || !av[1]) return 1;
	
	char *buf = malloc(sizeof(char) * 1024);
	if (!buf) return 1;
	ssize_t bytes_read = read(0, buf, 1024);
	if (bytes_read <= 0)
	{
		free(buf);
		return 0;
	}
	ft_filter(buf, av[1]);
	free(buf);
	return 0;
}