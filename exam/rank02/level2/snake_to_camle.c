

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	if (argc != 2 || !argv[1])
	{
		write(1, "\n",1);
		return 1;
	}
	int i =0;

	char *str = argv[1];
	int need_to_upper = 0;
	while (str[i])
	{
		if (str[i] == '_')
			need_to_upper = 1;
		
		if (need_to_upper && str[i] != '_')
		{
			str[i] -= 32;
			write(1, &str[i], 1);
			need_to_upper = 0;
			i++;
			continue;
		}
		if (!need_to_upper && str[i] != '_')
			write(1, &str[i], 1);

		i++;
	}
	write(1, "\n", 1);
}