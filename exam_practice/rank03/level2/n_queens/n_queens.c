#include <unistd.h>
#include <stdlib.h>



int ft_atoi(char *num)
{
	int res = 0;
	
	int i =0;
	while (num[i])
	{
		res = res * 10 + (num[i] - '0');
		i++;
	}
	return (res);
}

void ft_putnbr(int n)
{
	char c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void print_sol(int *pos, int n)
{
	int i=-1;
	
	while (++i < n)
	{
		ft_putnbr(pos[i]);
		if (i < n - 1) write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int ft_abs(int x)
{
	if (x < 0) x = -x;
	return x;
}

int	is_safe(int *pos, int col, int row)
{
	int i =0;
	while (i < col)
	{
		if (pos[i] == row) return (0);
		if (ft_abs(pos[i] - row) == col - i) return 0;
		i++;
	}
	return 1;
}

void	solve(int *pos, int n, int col)
{
	if (col == n)
	{
		print_sol(pos, n);
		return ;
	}
	int row = 0;
	while (row < n)
	{
		if (is_safe(pos, col, row))
		{
			pos[col] = row;
			solve(pos, n, col + 1);
		}
		row++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1]) return 1;

	int n = ft_atoi(argv[1]);
	int *pos = malloc(sizeof(int) * n);
	if (!pos) return 1;

	solve(pos, n, 0);
	free(pos);
}
