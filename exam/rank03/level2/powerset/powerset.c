

#include <stdlib.h>
#include <stdio.h>


int ft_atoi(char *n)
{
	int res  = 0, sign = 1;

	int i = 0;
	while (n[i] == ' ') i++;
	if (n[i] == '-') 
	{
		sign = -sign;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9') 
	{
		res = res * 10 + (n[i] - '0');
		i++;
	}
	return (res * sign);
}

void find_subset(int *set, int set_size, int target,
	int index, int *subset, int subset_size,
	int curr_sum)
{
	if (index == set_size)
	{
		if (curr_sum == target)
		{
			int i =0;
			while (i < subset_size)
			{
				printf("%d", subset[i]);
				if (i < subset_size - 1) printf(" ");
				i++;
			}
			printf("\n");
		}
		return;
	}
	subset[subset_size] = set[index];
	find_subset(set, set_size, target, index + 1, subset, subset_size + 1, curr_sum + set[index]);
	find_subset(set, set_size, target, index + 1, subset, subset_size, curr_sum);
}
int main(int ac, char **av)
{
	if (ac < 2) return 1;

	int size = ac -2;
	int target = ft_atoi(av[1]);
	int *set = malloc(sizeof(int) * size);
	int *subset = malloc(sizeof(int) * size);
	if (!set || !subset || size <= 0) return (1);
	int i = 0;
	while (i < size)
	{
		set[i] = ft_atoi(av[i + 2]);
		i++;
	}
	find_subset(set, size, target, 0, subset, 0, 0);
	free(set);
	free(subset);
	return (0);
}