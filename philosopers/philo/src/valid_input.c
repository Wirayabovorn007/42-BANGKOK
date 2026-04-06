
#include "../include/philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	valid_input(char **argv, int argc)
{
	int	i;
	int	j;

	if (argc > 6 || argc < 5)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (1);
		if (i != 4 && ft_atoi(argv[i]) <= 0)
			return (1);
		if (i == 4 && ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}
