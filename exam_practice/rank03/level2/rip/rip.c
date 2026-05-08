

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int is_balanced(char *s)
{
	int count = 0,  i=-1;

	while (s[++i])
	{
		if (s[i] == '(') count++;
		else if (s[i] == ')') count--;
		if (count < 0) return 0;
	}
	return count == 0;
}


void solve(char *s, int idx, int left, int right)
{
	if (left == 0 && right == 0)
	{
		if (is_balanced(s))
		{
			puts(s);
			return ;
		}
	}
	int i = idx;
	while (s[i])
	{
		if (i > idx  && (s[i] == s[i - 1])) {
			i++;
			continue;
		}

		if (left > 0 && s[i] == '(')
		{
			s[i] = ' ';
			solve(s, i + 1, left - 1, right);
			s[i] = '(';
		}
		if (right > 0 && s[i] == ')')
		{
			s[i] = ' ';
			solve(s, i + 1, left, right - 1);
			s[i] = ')';
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2) return 1;

	int left =0, right=0, i=-1;
	while (av[1][++i])
	{
		char c = av[1][i];
		if (c == '(') left++;
		else if (c == ')')
		{
			if (left > 0) left--;
			else right++;
		}
	}
	solve(av[1], 0, left, right);
	return 0;
}