/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:51:36 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/01/20 04:02:37 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*char_n;
	int		len;

	char_n = ft_itoa(n);
	len = ft_putstr(char_n);
	free(char_n);
	return (len);
}

static void	print_unsigned(unsigned int n)
{
	if (n > 9)
	{
		print_unsigned(n / 10);
		print_unsigned(n % 10);
	}
	else
		ft_putchar(n + '0');
}

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	ft_putunsigned(unsigned int n)
{
	if (n == 0)
		return (ft_putchar('0'));
	print_unsigned(n);
	return (get_size(n));
}
