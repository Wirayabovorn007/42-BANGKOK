

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}

	if (n < 10)
	{
		char c = n + '0';
		write(1, &c, 1);
	}else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void print_sol(int *n, int len)
{
	int i = -1;

	while (++i < len)
	{
		ft_putnbr(n[i]);
		if (i < len - 1) write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int ft_abs(int x)
{
	return (x * (x > 0)) - (x * (x <0));
}

int is_safe(int *pos, int row, int col)
{
	int i = 0;

	while (i < col)
	{
		if (pos[i] == row) return 0;
		if (ft_abs(pos[i] - row) == col - i) return 0;
		i++;
	}
	return 1;
}

void solve(int *pos, int col, int n)
{
	if (col == n)
	{
		print_sol(pos, n);
		return ;
	}
	int row = 0;
	while (row < n)
	{
		if (is_safe(pos, row, col))
		{
			pos[col] = row;
			solve(pos, col + 1, n);
		}
		row++;
	}
}


int main(int ac, char **av)
{
	if (ac != 2) return 1;

	int n = atoi(av[1]);
	int *pos = calloc(n, sizeof(int));
	if (!pos) return 1;

	solve(pos, 0, n);
	free(pos);
	return 0;
}


