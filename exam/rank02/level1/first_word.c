/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:16:17 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/24 14:32:17 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	char *str;
	int	char_found;
	
	if (!argv[1] || argc < 2)
		return 1;
	if (argc > 2)
	{
		write(1, "\n", 1);
		return 1;
	}
	i = 0;
	char_found = 0;
	str = argv[1];
	while (str[i])
	{
		if ((str[i] == ' '  || str[i] == '\t') && char_found)
			break ;
		if (str[i] != ' ' && str[i] != '\t') 
		{
			char_found = 1;
			write(1, &str[i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}