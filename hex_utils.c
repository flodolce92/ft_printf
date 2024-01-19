/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:04:57 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/01/20 04:10:36 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static void	print_hex(unsigned int n, char c)
{
	if (n > 15)
	{
		print_hex(n / 16, c);
		print_hex(n % 16, c);
	}
	else if (n > 9 && c == 'x')
		ft_putchar(n + 'a' - 10);
	else if (n > 9 && c == 'X')
		ft_putchar(n + 'A' - 10);
	else
		ft_putchar(n + '0');
}

int	ft_puthex(unsigned int n, char c)
{
	if (n == 0)
		return (ft_putchar('0'));
	print_hex(n, c);
	return (get_size(n));
}
