


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dist(float x1, float y1, float x2, float y2)
{
	return sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve_tsp(int n, float x[], float y[], int curr, int count, int mask, float current_dist, float *min_dist)
{
	if (current_dist >= *min_dist) return;

	if (count == n)
	{
		float total_dist = current_dist + dist(x[curr], y[curr], x[0], y[0]);
		if (total_dist <  *min_dist) *min_dist = total_dist;
		return ;
	}

	int i = 0;
	while (i < n)
	{
		if (!(mask & (1 << i))) {
			solve_tsp(n, x, y, i, count + 1, mask | (1 << i), current_dist + dist(x[curr], y[curr], x[i], y[i]), min_dist);
		}
		i++;
	}
}

int main(void)
{
	float x[15];
	float y[15];
	int n = 0;
	float curr_x, curr_y;

	while (fscanf(stdin, "%f, %f", &curr_x, &curr_y) == 2)
	{
		x[n] = curr_x;
		y[n] = curr_y;
		n++;
	}

	if (n == 0) return 0;
	if (n == 1) {
		fprintf(stdout, "0.00\n");
		return 0;
	}
	float min_dist = 1e9f;
	solve_tsp(n, x, y, 0, 1,1, 0.0f, &min_dist);
	fprintf(stdout, "%.2f\n", min_dist);
	return 0;
}


