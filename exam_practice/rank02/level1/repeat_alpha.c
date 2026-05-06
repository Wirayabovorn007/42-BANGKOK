/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiraya <wiraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:08:29 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/24 17:27:57 by wiraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int i =0;

	if (argc != 2 || !argv[1])
	{
		write(1, "\n", 1);
		return 1;
	}

	char *str;
	str = argv[1];
	int j;
	while (str[i])
	{
		j = -1;
		if (str[i] >= 'A' && str[i] < 'Z')
		{
			while (++j < str[i] - 64)
				write(1, &str[i], 1);
		}
		else if (str[i] >= 'a' && str[i] < 'z')
		{
			while (++j < str[i] - 96)
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}


	write(1, "\n", 1);
	return 0;
}