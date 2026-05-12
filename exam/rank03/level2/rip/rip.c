
#include <stdio.h>
#include <unistd.h>

int is_balanced(char *str)
{
	int count = 0;
	
	int i = -1;
	while (str[++i])
	{
		if (str[i] == '(') count++;
		else if (str[i] == ')') count--;

		if (count < 0) return 0;
	}
	return count==0;
}

void solve(char *str, int index, int left, int right)
{
	if (left == 0 && right == 0)
	{
		if (is_balanced(str))
		{
			puts(str);
			return ;
		}
	}
	int i = index;
	while (str[i])
	{
		if (i > index && str[i] == str[i - 1]) {
			i++;
			continue;
		}

		if (left > 0 && str[i] == '(')
		{
			str[i] = ' ';
			solve(str, index + 1, left - 1, right);
			str[i] = '(';
		}
		if (right > 0 && str[i] == ')')
		{
			str[i] = ' ';
			solve(str, index + 1, left, right - 1);
			str[i] = ')';
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1]) return 1;
	int left=0, right=0;

	int i = 0;
	while (av[1][i])
	{
		char c = av[1][i];
		if (c == '(') left++;
		else if (c == ')')
		{
			if (left > 0) left--;
			else right++;
		}
		i++;
	}
	solve(av[1], 0, left, right);
	return 0;
}