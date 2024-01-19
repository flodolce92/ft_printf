/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:46:31 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/01/23 16:39:50 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned long long n)
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

static void	print_pointer(unsigned long long n)
{
	if (n > 15)
	{
		print_pointer(n / 16);
		print_pointer(n % 16);
	}
	else if (n > 9)
		ft_putchar(n + 'a' - 10);
	else
		ft_putchar(n + '0');
}

int	ft_putpointer(unsigned long long n)
{
	if (n == 0)
		return (ft_putstr(NIL_STRING));
	ft_putstr("0x");
	print_pointer(n);
	return (get_size(n) + 2);
}
