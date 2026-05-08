#include <unistd.h>


int is_prime(int n)
{
	if (n <= 1)
		return 0;

	int i = 2;
	while (i <= n / 2)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (str[i])
	{
		if (str[i] == '-') sign = -sign;
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr(n / 10);
	n = (n % 10) + '0';
	write(1, &n, 1);
}

int main(int argc, char *argv[])
{
	if (argc != 2 || !argv[1])
	{
		write(1, "0", 1);
		return 1;
	}
	int n = ft_atoi(argv[1]);
	int sum = 0;

	while (n > 1)
	{
		if (is_prime(n))
			sum += n;
		n--;
	}
	putnbr(sum);
	write(1, "\n", 1);
}