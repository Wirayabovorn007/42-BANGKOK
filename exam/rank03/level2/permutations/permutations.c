#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *s)
{
	int i = -1;

	while (s[++i])
		write(1, &s[i], 1);
	write(1, "\n", 1);
}

int ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return (i);
}

void sort_str(char *str, int len)
{
	int i = 0, j, min;
	char tmp;

	while (i < len)
	{
		min = i;
		j = i + 1;
		while (j < len)
		{
			if (str[j] < str[i])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = str[i];
			str[i] = str[min];
			str[min] = tmp;
		}
		i++;
	}
}

void solve(char *str, char *res, int *used, int level, int len)
{
	int i =0;

	if (level == len)
	{
		str[level] = '\0';
		ft_putstr(res);
		return ;
	}

	while (i < len)
	{
		if (!used[i])
		{
			used[i] = 1;
			res[level] = str[i];
			solve(str, res, used, level + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1]) return 1;

	int len = ft_strlen(av[1]);
	char *res;
	int *used;

	res = malloc(sizeof(char) * (len + 1));
	used = calloc(sizeof(int), len);
	if (!res || !used) return 1;
	sort_str(av[1], len);
	solve(av[1], res, used, 0, len);

	free(res);
	free(used);
	return 0;
}
