

#include <unistd.h>

int	ft_atoi(char *s)
{
	int i = 0;
	int res = 0;
	
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return res;
}

void	putnbr(int n)
{
	if (n >= 10)
		putnbr(n / 10);
	n = (n%10) + '0';
	write(1, &n, 1);
}

int main(int argc, char *argv[])
{
	if (!argv[1] || argc != 2)
		return 1;
	int n = ft_atoi(argv[1]);
	int i =1, x = 0;
	while (i <= 9)
	{
		x= n*i;
		putnbr(i);
		write(1, " x ", 3);
		putnbr(n);
		write(1,  " = ", 3);
		putnbr(x);
		write(1,  "\n", 1);
		i++;
	}
	return 0;
}