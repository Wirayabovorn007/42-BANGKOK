typedef struct  s_point
{
	int	x;
	int	y;
}	t_point;


void	fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;

	if (tab[row][col] == 'F' || tab[row][col] != target)
		return ;
	
	tab[row][col] = 'F';

	fill(tab, size, target, row - 1, col);
	fill(tab, size, target, row + 1, col);
	fill(tab, size, target, row, col - 1);
	fill(tab, size, target, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];

	fill(tab, size, target, begin.y, begin.x);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// void print_tab(char **area)
// {
//     int i = 0;
//     while (area[i])
//     {
//         printf("%s\n", area[i]);
//         i++;
//     }
// }
// char **make_area(char **zone, int height)
// {
//     char **res = malloc(sizeof(char *) * (height + 1));
//     for (int i = 0; i < height; i++)
//         res[i] = strdup(zone[i]);
//     res[height] = 0;
//     return res;
// }
// int main(void)
// {
// 	char **area;
// 	t_point size = {8, 5};
// 	t_point begin = {2, 2};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};
// 	area = make_area(zone, size.y);
// 	flood_fill(area, size, begin);
// 	print_tab(area);
// 	return (0);
// }