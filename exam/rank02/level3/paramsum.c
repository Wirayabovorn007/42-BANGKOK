

#include <unistd.h>

void	pubnbr(int n)
{
	if (n >= 10)
		pubnbr(n / 10);
	n = (n % 10) + '0';
	write(1, &n, 1);
}

int	main(int argc, char *argv[])
{
	pubnbr(argc - 1);
	write(1, "\n", 1);
}