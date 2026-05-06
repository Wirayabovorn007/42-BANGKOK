/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:33:59 by wiboonpr          #+#    #+#             */
/*   Updated: 2025/11/24 14:59:06 by wiboonpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	write_num(int num)
{
	char c;

	if (num > 9)
		write_num(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

int main()
{
	int i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0)
			write(1, "fizz", 4);
		if (i % 5 == 0)
			write(1, "buzz", 4);
		if (!(i % 3 == 0 || i % 5 == 0))
			write_num(i);
		write(1, "\n", 1);
		i++;
	}
}