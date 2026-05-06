#include <stdio.h>

int is_balanced(char *s)
{
	int count = 0;
	int i = -1;

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

}


int main(int ac, char **av)
{
	if (ac != 2) return (1);

	char *s = av[1];
	int left=0, right=0;

	int i = -1;
	while (s[++i])
	{
		if (s[i] == '(') left++;
		else if (s[i] == ')')
		{
			if (left > 0) left--;
			else right++;
		}
	}

	solve(s, 0 , left, right);
	return (0);
}