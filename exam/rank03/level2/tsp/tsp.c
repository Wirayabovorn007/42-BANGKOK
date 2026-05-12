#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct s_city
{
	float x;
	float y;
}	t_city;

/*
** Calculates the Euclidean distance between 2 cities
*/
float	distance(t_city a, t_city b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrtf(dx * dx + dy * dy);
}

/*
** Computes total distance of the path
** including the return to the starting city
*/
float	total_distance(t_city *cities, int *path, int n)
{
	float total = 0.0f;
	
	for (int i = 0; i < n - 1; i++)
	{
		total += distance(cities[path[i]], cities[path[i + 1]]);
	}
	// Add the distance to return to the starting city
	total += distance(cities[path[n - 1]], cities[path[0]]);
	
	return total;
}

/*
** Uses backtracking to try all permutations
*/
void	solve(t_city *cities, int *path, int n, int pos, float *min)
{
	// Base case: we have a complete permutation
	if (pos == n)
	{
		float current_dist = total_distance(cities, path, n);
		if (current_dist < *min)
		{
			*min = current_dist;
		}
		return;
	}

	// Recursive step: generate permutations
	for (int i = pos; i < n; i++)
	{
		// Swap the current element with the element at 'pos'
		int temp = path[pos];
		path[pos] = path[i];
		path[i] = temp;

		// Recurse for the next position
		solve(cities, path, n, pos + 1, min);

		// Backtrack: swap back to restore the array state
		temp = path[pos];
		path[pos] = path[i];
		path[i] = temp;
	}
}

int	main(void)
{
	t_city	cities[11];
	int		n = 0;

	// Read input from stdin
	while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
		n++;

	// If less than 2 cities → distance = 0
	if (n < 2)
	{
		printf("0.00\n");
		return (0);
	}

	// Initialize path: [0,1,2,...]
	int path[11];
	for (int i = 0; i < n; i++)
		path[i] = i;

	float min = FLT_MAX;

	/*
	** Optimization:
	** Fix first city → start from pos = 1
	*/
	solve(cities, path, n, 1, &min);

	printf("%.2f\n", min);
	return (0);
}